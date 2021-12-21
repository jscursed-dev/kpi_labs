import java.util.Scanner;

public class RgrTr14Pryt {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double[][] matrix = {
                {8, -2, -10, -10, 3, 105.5},
                {5, -7, -4, -3, -1, 54.8},
                {9, 2, -10, 8, -3, 107.1},
                {3, 5, 2, -1, 6, 36.3},
                {-10, -5, 4, 7, -4, -102.3}
        };
        System.out.printf(
                "\n[TASK 1]\n\n" +
                        "Початкова матриця:"
        );
        task13(matrix);
        //System.out.printf("\n\n");
        //System.out.printf("Трикутникова матриця:");
        task13(task11(matrix));
        System.out.printf("\n\n");
        for (int i = 0; i < matrix.length; i++) {
            System.out.printf("\n\t");
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.printf("%.2lf ", matrix[i][j]);
            }
        }
        /*System.out.printf("\n\n");
        System.out.printf("Вектор результатів:");
        task13(task12(task11(matrix)));*/

        /*for(int i=100; i<1000; i++) {
            if ((i >= 100 && i < 1000) && ((i % 47 == 43) && (i % 43 == 47))) {
                System.out.printf("%d; ", i);
            }
            //System.out.printf("%d", i);
        }*/

        System.out.printf("\n\n[TASK 2]\n\n");
        for (int i = 0; i < 3; i++) {
            task2(scanner);
            System.out.printf("\n");
        }
    }

    public static double[][] task11(double[][] matrix) { // returns tringle-like matrix

        for (int i = 0; i < matrix.length - 1; i++) {
            int z = i + 1;
            do {
                double k = matrix[z][i] / matrix[i][i];              // i is row which I -
                int j = 0;                                           // z is row from which I -
                while (j < matrix[i].length) {                         // j is element of each row which -
                    matrix[z][j] = matrix[z][j] - matrix[i][j] * k;
                    j += 1;
                }
                z += 1;
            } while (z < matrix.length);
        }
        return matrix;
    }

    public static double[][] task12(double[][] tringleMatrix) {
        double[][] solution = new double[1][tringleMatrix.length];

        for (int i = tringleMatrix.length - 1; i >= 0; i--) {
            solution[0][i] = tringleMatrix[i][tringleMatrix[i].length - 1];
            int j = 0;
            while (j < tringleMatrix[i].length - 1) {
                if (j == i) {
                    j++;
                    continue;
                }
                solution[0][i] -= tringleMatrix[i][j] * solution[0][j];  //matrix[i][j] = /a/x solution = a/x/
                j++;
            }
            solution[0][i] = solution[0][i] / tringleMatrix[i][i];
        }

        return solution;
    }

    public static void task13(double[][] array) {
        for (int i = 0; i <= array.length - 1; i++) {
            System.out.printf("\n\t%d. ", i + 1);
            int j = 0;
            while (j < array[i].length) {
                if (array[i][j] % 1 != 0) {
                    System.out.printf("%.3f ", array[i][j]);
                } else {
                    System.out.printf("%.0f ", array[i][j]);
                }
                j++;
            }
        }
    }

    private static void task2(Scanner scanner) {
        System.out.printf("Введіть кількість елементів які буде проаналізовано: ");
        double[] arr = new double[scanner.nextInt()];
        for (int i = 0; i < arr.length; i++) {
            System.out.printf("Введіть число #%d: ", i + 1);
            arr[i] = scanner.nextDouble();
        }

        System.out.printf("Вхідні дані: ");
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 1 != 0) {
                System.out.printf("%.3f; ", arr[i]);
            } else {
                System.out.printf("%.0f; ", arr[i]);
            }
        }
        System.out.printf("\nРезультат: ");
        for (int i = 0; i < arr.length; i++) {
            if ((arr[i] >= 100 && arr[i] < 1000) && ((arr[i] % 47 == 43) && (arr[i] % 43 == 47))) {
                if (arr[i] % 1 != 0) {
                    System.out.printf("%.3f; ", arr[i]);
                } else {
                    System.out.printf("%.1f; ", arr[i]);
                }
            }
        }

    }
}