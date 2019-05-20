    #include<iostream>
    using namespace std;

    void seive(int maxElement,int isComposite[]){
        isComposite[0]=1;
        isComposite[1]=1;
        for(int i=2;i*i<=maxElement;i++){
            for(int j=2*i;j<=maxElement;j=j+i){
                isComposite[j]=1;
            }
        }
    }
    int main(){
    int maxElement= 1000000;
    int isComposite[1000001]={0};
    seive(maxElement,isComposite);
    for(int i=0;i<=maxElement;i++){
        if(isComposite[i]==0){
            cout<<i<<" ";
        }
    }

    }
