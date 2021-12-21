import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.printf("[TASK 1]\n| x | y | z |");
        for(double x=-6; x<=1; x+=0.2){
            System.out.printf("\n| %.2f | %.4f | %.4f |", x, Tasks.task1(x)[0], Tasks.task1(x)[1]);
        }

        System.out.printf("\n\n[TASK2]");
        double[][] array = new double[2][12];
        for(int i=0; i<array.length; i++){
            for(int j=0; j<array[i].length; j++){
                array[i][j]=j+i;
            }
        }
        for(int i=0; i<array.length; i++){
            System.out.printf("\nYour arrays:\n%d. ",i);
            for(double elem:array[i]){
                System.out.printf("%.4f, ", elem);
            }
            System.out.printf("Result: %d", Tasks.task2(array[i]));
        }

        System.out.printf("\n\n[TASK3]\n");
        double[] array1 = new double[2];
        for(int i=0; i<array1.length; i++){
            System.out.printf("Enter plese x%d: ", i+1);
            array1[i]=scanner.nextDouble();
        }
        scanner.close();
        for(double x:array1){
            System.out.printf("With x = %.4f summ = %.4f\n", x, Tasks.task3(x));
        }

    }
}