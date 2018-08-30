/**
 * Created by Lee on 2018/7/23.
 */
public class SelSort {
    public static void Sort(int a[]){
        int i,j,m;
        for (i = 0;i<a.length;i++){
            m = i;
            for(j = i+1;j<=a.length-1;j++) {
                if (a[m] > a[j])
                    m = j;
            }
            if(m!=j)
                Swap(a, m, i);
        }
    }

    public static void Out(int a[]){
        for(int num:a){
            System.out.print(num+" ");
        }
    }
    public static void Swap(int a[],int i,int j){
        int m;
        m = a[i];
        a[i] = a[j];
        a[j] = m;
    }

    public static void main(String arg[]){
        int[] a ={5,4,1,3,2};
        Sort(a);
        Out(a);
    }

}
