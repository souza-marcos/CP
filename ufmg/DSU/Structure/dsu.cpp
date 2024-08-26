class DSU{
private:
    int *arr;
    int *rank;

public:
    DSU(int max_size){
        arr = new int[max_size];
        rank = new int[max_size];
    }

    ~DSU(){
        delete[] arr;
    }

    void make_set(int n){
        arr[n] = n;
        rank[n] = 0;
    }

    int find_set(int x){
        if(arr[x] == x) return x;
        // Optimization: Path Compression
        return arr[x] = find_set(arr[x]); 
    }   

    void union_set(int x,int y){
        x = find_set(x);
        y = find_set(y);
        if(x != y) {
            if(rank[x] < rank[y]) {
                int aux = x;
                x = y;
                y = aux;
            }
            arr[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
};