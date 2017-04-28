#include <linux/init.h> 
#include <linux/module.h> 

static int hello_data __initdata = 3;

static short myshortdat = 120;
static int myintdat = 1234;
static char *p = "Mod param";
static int myarr[5] = {10, 20, 30, 40, 50};
static int arr_cnt = 5;
 
module_param(myshortdat, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshortdat, "A short integer");
module_param(myintdat, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myintdat, "An integer");
module_param(p, charp, 0000);
MODULE_PARM_DESC(p, "Character pointer");
module_param_array(myarr, int, &arr_cnt, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myarr, "Array of integers");

int __init hello_init(void)
{
	int i;
	printk (KERN_ALERT"short int is : %d\n", myshortdat);
	printk (KERN_ALERT"int is : %d\n", myintdat);
	printk (KERN_ALERT"my string is: %s\n", p);
	for (i = 0; i < arr_cnt; i++)
		printk (KERN_ALERT"arr[%d] = %d\n", i, myarr[i]);
	
	printk(KERN_ALERT"Hello, Kernel World!");
	return 0;
}

void __exit hello_exit(void) 
{
	printk(KERN_ALERT"Goodbye, Kernel World!"); 
}

MODULE_AUTHOR("NISHAD"); 
MODULE_LICENSE("GPL/v2"); 
MODULE_DESCRIPTION("Hello Kernel World!!");

module_init(hello_init); 
module_exit(hello_exit); 
