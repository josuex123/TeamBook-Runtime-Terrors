 //Busqueda binaria
 int l = -1, r = arr.size(), ans = -1;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(arr[mid] >= x){
            r = mid;
        }else{
            l = mid;
        }
    }

//Busqueda ternaria
int l = -1, r = n; 
while (r - l > 2) { 
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;

    if (arr[m1] < arr[m2]) {
        l = m1; 
    } else {
        r = m2; 
    }
}
int best = l + 1;
for (int i = l + 1; i < r; i++) {
    if (arr[i] > arr[best]) best = i; 
}
