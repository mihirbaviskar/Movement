#define Kp = a
#define Ki = b
//b<a
#define Kd = c
//c~a

void forwards_pid(int side, double target, double position, int speed)
{
    double current = get_create_lcliff_amt();
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
    //cmpc(LEFTWHEEL);
    if(side == 1){		//RIGHTSIDE
        
        /*while(gmpc(LEFTWHEEL) < position)*/
	while(1){
            current = get_create_lcliff_amt();
            error = target - current;
            integral=integral+error;
            //Sum of all errors(integral) should approach zero.
            //If integral is mostly positive then you are mostly on white and straying to the left
            //If integral is mostly negative then you are mostly on black and straying to the right
            integration=KI*integral;
            //Ki is some arbitrary value, Ki should most likely be lower than Kd and Kp
            proportional = KP * error;
            //increasing Kp makes it more drastic decreasing it makes it smoother
             derivative=error-last_error;
             derivation=KD * derivative;
		if(integration>200 || integration<-500){
                    integral=0;
                    integration=0;
                    printf("\tIntegration cleared");
                    //integration=abs(integration)*-1
                    //you have to use a certain header file to use abs
                    //this may make it too drastic
                }
          	correction = proportional + integration + derivation;
            printf("proportional: %lf   integration: %lf  derivation: %lf\n",proportional,integration,derivation);
            powerup = speed + correction;
            powerdown = speed - correction;
            printf("powerup: %lf\n",powerup);
            printf("powerdown: %lf\n",powerdown);
		//create_drive_straight(1000);
		//msleep(1000)
            mrp(LEFTWHEEL,powerdown, 8);							
            mrp(RIGHTWHEEL,powerup, 8);
            //printf("%i , %lfa , %lfb , %lfc , %i,  %lfa + %lfb + %lfc\n",counter,error, integral, derivative,counter,error, integral, derivative);
            //use to figure out define constants by pasting list in excel and the pasting that in desmos.Use slider to adjust values till graph matches sin(x)/x
            last_error=error;
            //used to find previous error
		}
        }
    
        if(side == 2){		//LEFTSIDE
        
        while(gmpc(LEFTWHEEL) < position)
        {
            current = analog(0);
            error = target - current;
            integral=integral+error;
            //Sum of all errors(integral) should approach zero.
            //If integral is mostly positive then you are mostly on white and straying to the left
            //If integral is mostly negative then you are mostly on black and straying to the right
            integration=KI*integral;
            //Ki is some arbitrary value, Ki should most likely be lower than Kd and Kp
            proportional = KP * error;
            //increasing Kp makes it more drastic decreasing it makes it smoother
             derivative=error-last_error;
             derivation=KD * derivative;
                if(integration>200 || integration<-500){
                    integral=0;
                    integration=0;
                    printf("\tIntegration cleared");
                    //integration=abs(integration)*-1
                    //you have to use a certain header file to use abs
                    //this may make it too drastic
                }
            correction = proportional + integration + derivation;
            printf("proportional: %lf   integration: %lf  derivation: %lf\n",proportional,integration,derivation);
            powerup = speed + correction;
            powerdown = speed - correction;
            printf("powerup: %lf\n",powerup);
            printf("powerdown: %lf\n",powerdown);
            mrp(LEFTWHEEL,powerdown, 8);							
            mrp(RIGHTWHEEL,powerup, 8);
            //printf("%i , %lfa , %lfb , %lfc , %i,  %lfa + %lfb + %lfc\n",counter,error, integral, derivative,counter,error, integral, derivative);
            //use to figure out define constants by pasting list in excel and the pasting that in desmos.Use slider to adjust values till graph matches sin(x)/x
            last_error=error;
            //used to find previous error
            counter=counter+1;
        	}
        }
	}	
