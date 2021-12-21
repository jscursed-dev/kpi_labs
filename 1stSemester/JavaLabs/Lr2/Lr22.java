import java.util.Scanner;

public class Lr22 {
    public static void main(String[] args){
        System.out.printf("\n------------[Task 3]------------\n");
        Scanner scanner = new Scanner(System.in);
        double params[][] = new double[3][3];
        for(int i = 0; i<params.length; i++){
            for(int j = 0; j<(params[i].length-1); j++){
                System.out.printf("Enter %dnd param from %d: ", j+1, i+1);
                params[i][j] = scanner.nextDouble();
            }
        }
        scanner.close();
        System.out.printf("\nResults:");
        for(int i = 0; i<params.length; i++){
            System.out.printf("\n%d. a = %.4f b = %.4f: %s", i+1, params[i][0], params[i][1], task3(params[i][0], params[i][1]));
            
        }
        double params1[][]={{2,9,474},{3,0,27},{4, 11, 30}};
        System.out.printf("\n\n------------[Task 4]------------\n");
        for(int i = 0; i<params1.length; i++){
            System.out.printf("\n%d. a = %.4f b = %.4f, c = %.4f: %s", i+1, params1[i][0], params1[i][1], params1[i][2], task4(params1[i][0], params1[i][1], params1[i][2]));
        }
    }

    public static String task3(double a, double b){        
        String y = "";

        if(Math.pow((a-b),2)>=Math.abs(Math.pow(a,2)-Math.pow(b,2))){
            y = "Square digit is bigger";
        }
        else{
            y = "|a^2-b^2| is bigger";
        }
        return y;
    }

    public static double task4(double a, double b, double c){        
        if((a==b)&&(a==c)){
            return 0;
        }
        if((a>=b)&&(a>=c)){
            return a;
        }
        if((b>=a)&&(b>=c)){
            return b;
        }
        if((c>=b)&&(c>=b)){
            return c;
        }
        return 0;
    }
}
