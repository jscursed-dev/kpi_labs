package lab1;
import java.util.Scanner;
import java.util.Date;

public class Lr1 {


    public static void main(String[] args){
      /*####################
        #  Main variables  #
        ####################*/
        double m = 2;
        double c = -1;   
        double t = 1.2;  
        double b = 0.7;
        
        System.out.printf("%nInput data:%nm = %1$.4f c = %2$.4f t = %3$.4f b = %4$.4f%nOutput data:%n", m, c, t, b);
        System.out.printf("R = %.4f;%n", calcR(m, c, t, b));
        System.out.printf("S = %.4f;%n", calcS(m, c, t, b));  
        
        System.out.printf("#2 Enther main variables%n");
        Scanner scanner = new Scanner(System.in);
        System.out.printf("m = ");
        m = scanner.nextDouble();
        System.out.printf("c = ");
        c = scanner.nextDouble();   
        System.out.printf("t = ");
        t = scanner.nextDouble();   
        System.out.printf("b = ");
        b = scanner.nextDouble();
        scanner.close();

        System.out.printf("%nInput data:%nm = %1$.4f c = %2$.4f t = %3$.4f b = %4$.4f%nOutput data:%n", m, c, t, b);
        System.out.printf("R = %.4f;%n", calcR(m, c, t, b));
        System.out.printf("S = %.4f;%n", calcS(m, c, t, b));      
        outputDate();

    }
    
    /*################### 
      #     Methods     #
      ###################*/

    public static double calcR(double m, double c, double t, double b){
        double r = Math.cbrt(m*Math.tan(t)+Math.abs(c*Math.sin(t))); 
        return r;
    }

    public static double calcS(double m, double c, double t, double b){
        double s = m*Math.cos(b*t*Math.sin(t))+c;
        return s;
    }

    public static void outputDate(){
        Date date = new Date();
        System.out.printf("Current date: %1$td/%1$tm/%tY, Local time: %1$tH:%1$tM:%1$tS:%1$tL", date);
        return;
    }

}
 