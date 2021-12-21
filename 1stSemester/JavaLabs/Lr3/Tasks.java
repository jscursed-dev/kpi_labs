public class Tasks {
    
    public static double[] task1(double x){
        double[] result = new double[2];
        result[0] = 1.5*Math.cos(x-Math.PI/(4*Math.pow(Math.E, x)));
        result[1] = Math.atan(x+3.1);
        return result;
    }
    
    public static int task2(double[] array){
        int counter=0;
        for(int i=1; i<array.length; i+=2){
            if(array[i]%2!=0){
                counter+=1;
            }
        }
        return counter;
    }

    public static double task3(double x){
        double r=0;
        for(int k=1; k<=8; k++){
            r += (2*Fact.fact(k)*Math.cos(Math.PI-x))/Math.pow(x, 2*k-1);
        }
        return r;
    }

}


