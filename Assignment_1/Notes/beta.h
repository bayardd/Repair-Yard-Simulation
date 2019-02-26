class beta
{
public:
    beta(){}
    beta(int k){key = k;}
    void addVal(default_random_engine* gptr)
        {
            uniform_int_distribution<int> Idist(1,100);
            int v = Idist(*gptr);
            ///if v divided by key has remainder 0 add it to the list
            if((v%key)==0)
            {
                Ilist.push_back(v);
            }
            else
            {
                Flist.push_back(v);
            }
        }
    void display()
    {
        cout<<"beta with key = "<<key<<endl;
        Litr = Ilist.begin();
        cout<<" Accept list [ ";
        while(Litr!=Ilist.end())
        {
            cout<<*Litr;
            Litr++;
            if(Litr!=Ilist.end()){cout<<", ";}
            else{cout<<" ";}
        }
        cout<<" ] "<<endl;
        cout<<" Reject list [ ";
        Litr=Flist.begin();
        while(Litr!=Flist.end())
        {
            cout<<*Litr;
            Litr++;
            if(Litr!=Flist.end()){cout<<", ";}
            else{cout<<" ";}
        }
        cout<<" ] "<<endl<<endl;
    }
    void init()
    {
        Ilist.sort();
        Ilist.unique();
        Flist.sort();
        Flist.unique();
    }
    void findval(int t)
    {
        Litr=Ilist.begin();
        while(Litr!=Ilist.end())
        {
            if (t == *Litr){cout<<t<<" found in accepted list"<<endl;}
            Litr++;
        }
    }
private:
    int key;
    list<int> Ilist;
    list<int>::iterator Litr;
    list<int> Flist;


};
