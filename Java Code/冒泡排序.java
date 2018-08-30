/**
 * Created by Lee on 2018/7/23.
 */
public class BubSort {
    public static int [] Bub(int[] a) {
        int flag = 1;
        for (int i = 0; i < a.length - 1; i++) {
            flag = 0;
            if (flag == 0) {
                for (int j = a.length - 1; j > i; j--) {
                    if (a[j] < a[j - 1]) {
                        Swap(a, j, j - 1);
                        flag = 1;
                    }
                }
            }
        }
        return a;
    }

    public static void Out(int a[]){
        for(int num:a)
            System.out.print(num+" ");
    }

    public static void Swap(int a[],int i,int j){
        int m;
        m = a[i];
        a[i] = a[j];
        a[j] = m;
    }

    public static void main(String args[]){
        int[] a = {5,4,1,3,2,8};
        Bub(a);
        Out(a);
    }
}
