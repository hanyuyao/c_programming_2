#include <iostream>
#include <string>

using namespace std;

int countInsertion()
{
    int n;
    int counting = 0;
    int* s = nullptr;
    cin >> n;
    s = (int*)malloc(n * sizeof(int));

    for(int k = 0; k < n; k++)
        cin >> s[k];

    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j > 0; j--){
            if(s[j] < s[j-1]){
                int temp = s[j];
                s[j] = s[j-1];
                s[j-1] = temp;
                counting++;
            }
            else
                break;
        }
    }

    free(s);
    return counting;
}

int main()
{
    int total;
    cin >> total;

    int output = 0;
    while(total--){
        output += countInsertion();
    }
    cout << output << endl;
}
