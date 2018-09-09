
#define Kp = a
#define Ki = b
//b<a
#define Kd = c
//c>a

void forwards_pid_mihir(int side, double target, double position, int speed)
{
    double current = analog(0);
    double error = target - current;
    double proportional;
    double integral;
    double integration;
    double last_error;
    double derivative;
    double derivation;
    double powerup;
    double powerdown;
    double correction;
    int counter=0;
    cmpc(LEFTWHEEL);

    if(side == 1)		//RIGHTSIDE
    {
        while(gmpc(LEFTWHEEL) < position)
        {
            current = analog(0);
            error = target - current;
            integral=integral+error;
            //Sum of all errors(integral) should approach zero.
            //If integral is mostly positive then you are mostly on white and straying to the left
            //If integral is mostly negative then you are mostly on black and straying to the right
            integration=Ki*integral;
            //Ki is some arbitrary value, Ki should most likely be lower than Kd and Kp
            proportional = Kp * error;
            //increasing Kp makes it more drastic decreasing it makes it smoother
            
                if(counter!=0){
                    //This is because last_error is still 0 and will only have a value at the second iteration
                    derivative=last_error-error;
                    derivation=Kd * derivative;
                    correction = proportional + integration + derivation;
        	        }
                else{
                    correction = proportional
                    printf("\t ONLY USING PROPORTIONAL");
                    }
                if(error<0){
                    integration=abs(integration)*-1
                    derivation=abs(derivation)*-1
                    //you have to use a certain header file to use abs
                    //this may make it too drastic
                }
          
            printf("proportional: %lf   integration: %lf  derivation: %lf\n",proportional,integration,derivation);
            powerup = speed + correction;
            powerdown = speed - correction;
            printf("powerup: %lf\n",powerup);
            printf("powerdown: %lf\n",powerdown);
            mrp(LEFTWHEEL,powerdown, 4);							
            mrp(RIGHTWHEEL,powerup, 4);
            //printf("%i , %lfa , %lfb , %lfc , %i,  %lfa + %lfb + %lfc",counter,error, integral, derivative,counter,error, integral, derivative);
            //use to figure out defines by pasting list in excel and the pasting that in desmos.Use slider to adjust values till graph matches sin(x)/x
            last_error=error;
            //used to find previous error
            counter=counter+1
        }
    }
