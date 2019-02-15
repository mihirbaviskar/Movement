#define KPR
#define KPL

void align(int side, double target)
{
    double currentleft = get_create_lcliff_amt();
    double currentright = get_create_rcliff_amt();
    double errorleft = currentleft-target;
    double errorright = currentright-target;
    double lproportional;
    double rproportional;
    cmpc(LEFTWHEEL);
    if(side == 1){		//UNDERLINE
        
        while()                 //not on ngrey
           {
		 double currentleft = get_create_lcliff_amt();
		 double currentright = get_create_rcliff_amt();
		 double errorleft = currentleft-target;
    		 double errorright = currentright-target;
		 lproportional = KPL * errorleft;
		 rproportional = KPR * errorright;
		 printf("lproportional: %lf\n",lproportional);
		 printf("rproportional: %lf\n",rproportional);
		 create_drive_direct(lproportional,rproportional);
           }
        }
    
     if(side == 2){		//OVERLINE
        
        while()                 //not on grey
           {
		 double currentleft = get_create_lcliff_amt();
		 double currentright = get_create_rcliff_amt();
		 double errorleft = target-currentleft;
    		 double errorright = target-currentright;
		 lproportional = KPL * errorleft;
		 rproportional = KPR * errorright;
		 printf("lproportional: %lf\n",lproportional);
		 printf("rproportional: %lf\n",rproportional);
		 create_drive_direct(lproportional,rproportional);
           }
      }
}
