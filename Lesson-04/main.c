int main() {
    int counter = 0;
    
    //Clock Gating - Enable GPIOF
    int *gpiof = (int*)0x400FE608U;
    *gpiof = 0x20U;
    
    //GPIO pin direction register - GPIODIR in data sheet - Setting bit to 1 makes corresponding pin an output pin
    int *gpiodir = (int*)0x40025400U;
    *gpiodir = 0x0EU;
    
    //Digital function register - In data sheet: GPIODEN - GPIO Digital Enable
    int *gpioden = (int*)0x4002551CU;
    *gpioden = 0x0EU;
    
    int *gpiofDataReg = (int*)0x400253FCU;
    *gpiofDataReg = 0x00U;
    
    while(1)
    {
        *gpiofDataReg = 0x02U; // Turns Red LED on
        while(counter < 1000000)
        {
            ++counter;
        }
        counter = 0;
        
        *gpiofDataReg = 0x00U; // Turns LED off
        while(counter < 1000000)
        {
            ++counter;
        }
        counter = 0;
    }
    
    return 0;
}