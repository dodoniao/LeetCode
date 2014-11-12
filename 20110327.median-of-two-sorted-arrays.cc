class Solution {
public:
    int findKthSmallest(int A[], int m, int B[], int n, int k)
    {
        if(m == 0) return B[k-1];
        else if(n == 0) return A[k-1];
        if(k == 1) return (A[0] < B[0] ? A[0] : B[0]);
        
        int ia = m * (k - 1) * 1.0 / (m + n);
        int ib = k - ia - 2;
        if(A[ia] == B[ib]) return A[ia];
        else if(A[ia] > B[ib]) return findKthSmallest(A, ia+1, B+ib+1, n-ib-1, k-ib-1);
        else return findKthSmallest(A+ia+1, m-ia-1, B, ib+1, k-ia-1);
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int ma = m / 2, mb = n / 2;
        if(m == 0 && n == 0) return 0;
        else if(m == 0)
        {
            if(n % 2 == 0) return (B[mb] + B[mb-1]) / 2.0;
            else return B[mb];
        }
        else if(n == 0)
        {
            if(m % 2 == 0) return (A[ma] + A[ma-1]) / 2.0;
            else return A[ma];
        }
        else
        {
            if((m + n) % 2 == 0)
            {
                int med = (m + n) / 2;
                int ml = findKthSmallest(A, m, B, n, med);
                int mr = findKthSmallest(A, m, B, n, med+1);
                return (ml + mr) / 2.0;
            }
            else return findKthSmallest(A, m, B, n, (m+n+1)/2);
        }
    }
};
