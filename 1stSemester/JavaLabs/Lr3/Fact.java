public class Fact {
    static int fact(int n){
        n = Math.abs(n);
        int r = 1;
        while(n>0){
            r=r*n;
            n+=-1;
        }
        return r;
    }    
}
