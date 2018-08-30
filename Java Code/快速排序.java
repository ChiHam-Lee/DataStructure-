/**
 * Created by Lee on 2018/7/23.
 */
public class Quick {
    public static void QuickSort(int a[],int low ,int high){
        int i,j,key;
        i = low;j = high;
        if(low<high) {
            key = a[low];
            while (i < j) {
                while (i < j && a[j] >= key)
                    j--;
                if (i < j)
                    a[i] = a[j];

                while (i < j && a[i] <= key)
                    i++;
                if (i < j)
                    a[j] = a[i];
            }
            a[i] = key;
            QuickSort(a, low, i - 1);
            QuickSort(a, i + 1, high);
        }
    }

    public static void main(String args[]){
        int[] a ={5,1,3,4,2,9};
        QuickSort(a,0,a.length-1);
        for(int num:a)
            System.out.print(num+" ");
    }
}
