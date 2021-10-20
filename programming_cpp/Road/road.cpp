#include <iostream>

using namespace std;

int main()
{
    //cerr << "Ut" << endl;
    int N,M;
    cerr << "Ut hossza: "; cin >> N;
    cerr << "Felujitasok szama: "; cin >> M;

    int kezdo_km[M], vege_km[M];

    for (int i=0; i<M; ++i)
    {
        cin >> kezdo_km[i] >> vege_km[i];
    }

    // 1. feladat

    int min_length=vege_km[0]-kezdo_km[0];

    for(int i=0; i<M; ++i)
    {
        if(min_length > vege_km[i]-kezdo_km[i])
        {
            min_length= vege_km[i]-kezdo_km[i];
        }
    }
    cout << min_length << endl;

    // 2. feladat
    int counter=0;
    int km=0;

    for(km=0; km<=N && counter < 3; ++km)
    {
        counter=0;
        for(int i=0; i<M && counter <3; ++i)
        {
            if( km >= kezdo_km[i] && km <= vege_km[i])
            {
                counter++;
            }
        }
    }

    if(km-1==N)
    {
        km=-1;
        cout << km << endl;
    }
    else{
        cout << km -1 << endl;
    }


    // 3. feladat

    int renovated[N];

    for(int i=0; i<N; ++i)
    {
        renovated[i]=0;
    }


    for(int i=0; i<M; ++i)
    {
        for(int j=kezdo_km[i]; j<vege_km[i]; ++j)
        {
            renovated[j]=1;

        }
    }

    int to_be_renovated_sum=0;

    for(int i=0; i<N; ++i)
    {
        if(renovated[i]==0)
        {
            to_be_renovated_sum++;
        }
    }
    cout << to_be_renovated_sum << endl;

    // 4. feladat

    int not_renovated_length=0;
    int not_renovated_length_max=0;

    int index = 0;

    while(index < N)
    {
        for(int i=index; renovated[i]==0 && i<N; ++i)
        {
            not_renovated_length++;
        }
        if(not_renovated_length==0)
        {
            index++;
        }
        else
        {
            if(not_renovated_length_max < not_renovated_length)
            {
                not_renovated_length_max= not_renovated_length;
            }
            index+=not_renovated_length;
            not_renovated_length=0;
        }

    }


    cout << not_renovated_length_max;

    return 0;
}
