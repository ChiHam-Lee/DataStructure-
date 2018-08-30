/**
 * Created by Lee on 2018/7/23.
 */
public class Heap {

    public static void main(String args[]){
        int n;
        int[] a = {5,4,1,3,2};
        n = a.length-1;
        HeapSort(a,n);
        Out(a);
    }

    public static void Swap(int a[],int i,int j){
        int m;
        m = a[i];
        a[i] = a[j];
        a[j] = m;
    }

    public static void HeapAdjust(int a[], int small, int max) {
        int m,i;
        m = a[small];
        for(i = small*2+1;i<=max;i = i*2+1) {
            if (i < max && a[i + 1] > a[i])
                i++;
            if (!(m < a[i]))
                break;
            a[small] = a[i];
            small = i;
        }
        a[small] = m;
    }

    public static  void HeapSort(int a[],int n){
        int i;
        for(i = n/2-1;i>=0;i--)
            HeapAdjust(a,i,n-1);
        for(i = n;i>0;i--) {
            Swap(a, 0, i);
            HeapAdjust(a, 0, i - 1);
        }
    }
    public static  void Out(int a[]){
        for(int num:a)
            System.out.print(num+" ");
    }
}