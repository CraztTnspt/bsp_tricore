#include "Cpu0_Main.h"
#include "headfile.h"
#include "rtthread.h"

#pragma section all "cpu0_dsram"

int core0_main(void)
{
extern int rtthread_startup(void);

    disableInterrupts();
	get_clk();

	uart_init(UART_0, 115200, UART0_TX_P14_0, UART0_RX_P14_1);

    rtthread_startup();

    rt_kprintf("Failed to start rt-thread.\n");

    while(1);

}

void GPIO_Demo_init(void)
{
    /* configure P20.8 as general output */
    IfxPort_setPinMode(&MODULE_P20, 8,  IfxPort_Mode_outputPushPullGeneral);
    /* configure P20.9 as general output */
    IfxPort_setPinMode(&MODULE_P20, 9,  IfxPort_Mode_outputPushPullGeneral);
    /* configure P21.4 as general output */
    IfxPort_setPinMode(&MODULE_P21, 4,  IfxPort_Mode_outputPushPullGeneral);
    /* configure P21.5 as general output */
    IfxPort_setPinMode(&MODULE_P21, 5,  IfxPort_Mode_outputPushPullGeneral);
}

static rt_uint8_t led_thread_stack[2048];
struct rt_thread led_thread_thread;
void led_thread_entry(void *parameter)
{
    while(1)
    {
        IfxPort_togglePin(&MODULE_P20, 8);
        IfxPort_togglePin(&MODULE_P20, 9);
        rt_thread_mdelay(1000);
        IfxPort_togglePin(&MODULE_P21, 4);
        IfxPort_togglePin(&MODULE_P21, 5);
    }
}
void led_demo_start(void){

    rt_thread_t tid;
    rt_err_t result;
    GPIO_Demo_init();
    tid = &led_thread_thread;
    result = rt_thread_init(tid, "led", led_thread_entry, RT_NULL,
                led_thread_stack, sizeof(led_thread_stack), 10, 20);
    RT_ASSERT(result == RT_EOK);
    rt_thread_startup(tid);
    rt_kprintf("Application auto init ok!\n");
}
INIT_APP_EXPORT(led_demo_start);

char get_char_test(void){
    Ifx_SizeT count = 1;
    uint8     data;

    while (IfxAsclin_Asc_read(uart_get_handle(UART_0), &data, &count, TIME_INFINITE) != TRUE)
    {
        rt_thread_mdelay(10);
    }

    return data;
}

int main(void)
{
    rt_kprintf("hello rt-thread!\n");
    while(1)
    {
        char ch;
        uart_getchar(UART_0,&ch);
        rt_kprintf("%c",ch);
        rt_thread_mdelay(1000);
    }
}


#pragma section all restore
