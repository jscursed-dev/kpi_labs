
public class Lr21{
    public static void main(String[] args){
        System.out.printf("\n------------[Task 1]------------");
        double x1 = -2.3;
        double x2 = 0.6;
        double x3 = 4.8;

        System.out.printf("\n1. x = %.4f: %.4f\n2. x = %.4f: %.4f\n3. x = %.4f: %.4f\n\n", x1, task1(x1), x2, task1(x2), x3, task1(x3));
//        Lr22.task3(1,1);
        System.out.printf("------------[Task 2]------------");
        x1 = -2.3;
        x2 = 0.6;
        x3 = 4.8;
        double params[][]={
            {0.3, 0.9, Math.sin(Math.pow(x1, 2))},
            {4.3, 3.15, Math.sin(Math.pow(x1, 3))},
            {6.5, 3.5, Math.pow(Math.sin(x1),2)}
        };
        System.out.printf(
            "\n1. x1 = %.4f\n\t1) a = %.4f, b = %.4f, z = %.4f: \n\t2) a = %.4f, b = %.4f, z = %.4f: \n\t3) a = %.4f, b = %.4f, z = %.4f: \n",
            x1, params[0][0], params[0][1], params[0][2], params[1][0], params[1][1], params[1][2], params[2][0], params[2][1], params[2][2]
        );
        params[0][2] = Math.sin(Math.pow(x2, 2));
        params[1][2] = Math.sin(Math.pow(x2, 3));
        params[2][2] = Math.pow(Math.sin(x2),2);
        System.out.printf(
            "2. x2 = %.4f\n\t1) a = %.4f, b = %.4f, z = %.4f: \n\t2) a = %.4f, b = %.4f, z = %.4f: \n\t3) a = %.4f, b = %.4f, z = %.4f: \n",
            x2, params[0][0], params[0][1], params[0][2], params[1][0], params[1][1], params[1][2], params[2][0], params[2][1], params[2][2]
        );
        params[0][2] = Math.sin(Math.pow(x3, 2));
        params[1][2] = Math.sin(Math.pow(x3, 3));
        params[2][2] = Math.pow(Math.sin(x3),2);
        System.out.printf(
            "3. x3 = %.4f\n\t1) a = %.4f, b = %.4f, z = %.4f: \n\t2) a = %.4f, b = %.4f, z = %.4f: \n\t3) a = %.4f, b = %.4f, z = %.4f: \n",
            x3, params[0][0], params[0][1], params[0][2], params[1][0], params[1][1], params[1][2], params[2][0], params[2][1], params[2][2]    
        );


    }

    public static double task2(double x, double a, double b, double z){        
        double y=0;

        if(x<a){
            y = a+b*x+Math.pow(Math.sin(z*Math.pow(x, 3.5)),2);
        }
        if((a<=x)&&(x<=Math.pow(b,2))){
            y = a*Math.log(Math.abs(a*b-z*Math.pow(x,3)))+Math.log(x);
        }
        if(x>Math.pow(b,2)){
            y = Math.sqrt(Math.abs(a+1/Math.tan(z*x)))+b*Math.sin(x);
        }
        return y;
    }

    public static double task1(double x){        
        final double a = 10;
        final double b = 0.7;
        final double c = 3.7;
        double y = 0;
        
        if (x<a){
            y = Math.cbrt(b+Math.sqrt(Math.abs(x+c)));
        }
        if ((x>=a) && (x<=Math.pow(b, 2))){
            y = Math.cos(x-b-c);
        }
        if (x>Math.pow(b, 2)){
            
        }
        return y;
    }
}
