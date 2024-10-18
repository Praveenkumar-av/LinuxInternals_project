// sum.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple Linux module that calculates the sum of two numbers");

// Define parameters
static int num1 = 1;  // Default value 1
static int num2 = 2;  // Default value 2

// Register module parameters and provide descriptions
module_param(num1, int, S_IRUGO);
MODULE_PARM_DESC(num1, "First integer number");
module_param(num2, int, S_IRUGO);
MODULE_PARM_DESC(num2, "Second integer number");

// Module init function (called when the module is loaded)
static int __init sum_init(void) {
    int result = num1 + num2;
    printk(KERN_INFO "Sum Module Loaded: num1 = %d, num2 = %d, sum = %d\n", num1, num2, result);
    return 0;  // Return 0 to indicate successful loading
}

// Module exit function (called when the module is unloaded)
static void __exit sum_exit(void) {
    printk(KERN_INFO "Sum Module Unloaded\n");
}

// Register module entry and exit points
module_init(sum_init);
module_exit(sum_exit);

