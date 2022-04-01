#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pl> vpl;
typedef vector<pi> vpi;
#define fl(i,a,b) for(ll i = a; i < b; i++)
#define fr(i,a,b) for(ll i = a; i >=b; i--)
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define trav(v,i) for (auto i = v.begin(); i != v.end(); i++)
#define f(c, x)(c.find(x) != c.end())
#define f1(c, x)(find(all(c), x) != c.end())
#define inf 2e15
#define mod 1e9+7
#define in(arr,z) for(ll i=0; i<z; i++) cin>>arr[i]
#define out(arr,z) for(ll i=0; i<z; i++) cout<<arr[i]<<' '

class user{
    public:
        string name;
        string id;
        string password;
        string category;
        int count;
        user(string name, string id, string password, string category){
            this->name=name;
            this->id=id;
            this->password=password;
            this->count=0;
            this->category=category;
        }
};

class book{
    public:
        string title;
        string author;
        string isbn;
        string publication;
        int fine;
        book(string title, string author, string isbn, string publication){
            this->title=title;
            this->author=author;
            this->isbn=isbn;
            this->publication=publication;
            this->fine=0;
        }
};

class user_db{
    public:
        vector<user> users;

        int search(string id){
            trav(users,i){
                if((*i).id==id)
                    return 1;
            }
            return 0;
        }

        void add(string name, string id, string password, string category){
            if(search(id))
                return;
            user* u = new user(name,id,password,category);
            users.pb(*u);
        }

        void del(string id){
            trav(users,i){
                if((*i).id==id){
                    users.erase(i);
                    break;
                }
            }
        }

        void update(string id, string name1, string id1, string password1, string category){
            trav(users,i){
                if ((*i).id==id){
                    (*i).name=name1;
                    (*i).id=id1;
                    (*i).password=password1;
                    if((*i).category!=category){
                        (*i).category=category;
                        //add delete the object
                    }
                }
            }
        }

        void display_u(){
            int count=1;
            trav(users,i){
                cout << count << ". " << "Name: " << (*i).name << " ID: " << (*i).id << " Category: " << (*i).category << endl;
                count++;
            }
        }

};

class book_db{
    public:
        vector<book> books;
        map<string,string> data;
        void display_b(){
            int count=1;
            trav(books, i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
                count++;
            }
        }

        int search(string title, string author, string isbn, string publication){
            trav(books, i){
                if ((*i).title == title && (*i).author == author && (*i).isbn == isbn && (*i).publication == publication)
                    return 1;
            }
            return 0;
        }

        void add(string title, string author, string isbn, string publication){
            if (search(title,author,isbn,publication))
                return;
            book* b=new book(title,author,isbn,publication);
            books.pb(*b);
        }

        void del(string title){
            trav(books, i){
                if ((*i).title == title){
                    books.erase(i);
                    break;
                }
            }
        }

        void update(string title, string title1, string author1, string isbn1, string publication1){
            trav(books, i){
                if ((*i).title == title){
                    (*i).title == title1;
                    (*i).author == author1;
                    (*i).isbn == isbn1;
                    (*i).publication = publication1;
                }
            }
        }

};

class prof : public user{
    public:
        void display_b(book_db& bookdb){
            int count=1;
            trav(bookdb.books, i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
                count++;
            }
        }
        prof(string name,string id,string password,string category):user(name,id,password,category){}
        vector<book> list;
        void display_list(){
            int count=1;
            trav(list,i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
            }
        }
        void issue(string title, string author, book_db& database){
            trav(database.books,i){
                if((*i).title == title && (*i).author == author && !f(database.data,i->isbn)){
                    list.pb(*i);
                    database.data[(*i).isbn]=id;
                    count++;
                }
            }
        }
        int issuable(string title, string author, book_db& database){
            trav(database.books,i){
                if((*i).title == title && (*i).author == author && !f(database.data,i->isbn)){
                    return 1;
                }
            }
            return 0;
        }
};

class student : public user{
    public:
        void display_b(book_db& bookdb){
            int count=1;
            trav(bookdb.books, i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
                count++;
            }
        }
        vector<book> list;
        void display_list(){
            int count=1;
            trav(list,i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
            }
        }
        student(string name,string id,string password,string category):user(name,id,password,category){}
        void limit(){
            cout<< "You can issue only 5 books at max!"<<endl;
        }

        void issue(string title, string author, book_db& database){
            trav(database.books,i){
                if((*i).title == title && (*i).author == author && !f(database.data,i->isbn)){
                    if(count>=5){
                        limit();
                        return;
                    }
                    list.pb(*i);
                    database.data[(*i).isbn]=id;
                    count++;
                }
            }
        }

        int issuable(string title, string author, book_db& database){
            trav(database.books,i){
                if((*i).title == title && (*i).author == author && !f(database.data,i->isbn)){
                    return 1;
                }
            }
            return 0;
        }
    
};

class librarian : public user{
    public:
        librarian(string name,string id,string password,string category):user(name,id,password,category){}
        void add_book(book_db& bookdb){

        }
        void delete_book(book_db& bookdb){

        }
        void update_book(book_db& bookdb){
            
        }
        void display_b(book_db& bookdb){
            int count=1;
            trav(bookdb.books, i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
                count++;
            }
        }
        void display_u(user_db& userdb){
            int count=1;
            trav(userdb.users,i){
                cout << count << ". " << "Name: " << (*i).name << " ID: " << (*i).id << " Category: " << (*i).category << endl;
                count++;
            }
        }
        void user_book_list(string id,book_db& bookdb,user_db& userdb){
            trav(bookdb.data,i){
                if(i->second==id){
                    trav(bookdb.books,j){
                        if(j->isbn==i->first){
                            cout << "Title: " << j->title << "  Author: " << j->author << " ISBN: " << j->isbn << " Publication: " << j->publication << endl;
                        }
                    }
                }
            }  
        }

        void user_book_mapping(book_db& bookdb,user_db& userdb){
            int count=1;
            trav(bookdb.data,i){
                cout << count << ". ";
                trav(bookdb.books,j){
                    if(j->isbn==i->first){
                        cout << "Book - " << "Title: " << j->title << " Author: " << j->author << " ISBN: " << j->isbn << " Publication: " << j->publication << endl;
                    }
                }
                trav(userdb.users,k){
                    if(k->id==i->second){
                         cout << "User - " << " Name: " << (*k).name << " ID: " << (*k).id << endl;
                    }
                }
                count++;
            }
        }

};

class prof_db{
    public:
        vector<prof> profs;
        int search(string id){
            trav(profs,i){
                if((*i).id==id)
                    return 1;
            }
            return 0;
        }

        void add(string name, string id, string password){
            if(search(id))
                return;
            prof p = prof(name,id,password,"PROFESSOR");
            profs.pb(p);
        }

};

class student_db{
    public:
        vector<student> students;
        int search(string id){
            trav(students,i){
                if((*i).id==id)
                    return 1;
            }
            return 0;
        }

        void add(string name, string id, string password){
            if(search(id))
                return;
            student s = student(name,id,password,"STUDENT");
            students.pb(s);
        }

};

class librarian_db{
    public:
        vector<librarian> librarians;
        int search(string id){
            trav(librarians,i){
                if((*i).id==id)
                    return 1;
            }
            return 0;
        }

        void add(string name, string id, string password){
            if(search(id))
                return;
            librarian l = librarian(name,id,password,"LIBRARIAN");
            librarians.pb(l);
        }

};

void home(user_db& ,prof_db&,student_db &,librarian_db &,book_db&);

void registration(user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb, book_db& bookdb){
    string id,password1,password2,name;
    cout<<"Name : ";
    cin>>name;
    cout<<"ID : ";
    cin>>id;
    if(database.search(id)){
        cout<<endl<<"ID already exists. Try again."<<endl;
        registration(database,profdb,studentdb,librariandb,bookdb);
        return;
    }
    cout<<"Password : ";
    cin>>password1;
    cout<<"Confirm Password : ";
    cin>>password2;
    if(password1!=password2){
        cout<<endl<<"Passwords don't match. Try again."<<endl;
        registration(database,profdb,studentdb,librariandb,bookdb);
        return;
    }
    cout<<"Register as:"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Professor"<<endl;
    cout<<"3. Librarian"<<endl;
    cout<<"Write the number of your choice, according to the above list. For example, 1 for Student."<<endl;
    int num;
    cin>>num;
    cout<<endl;
    switch(num){
        case 1:
            database.add(name,id,password1,"STUDENT");
            studentdb.add(name,id,password1);
            cout<<"Successful Registration"<<endl;
            break;
        case 2:
            database.add(name,id,password1,"PROFESSOR");
            profdb.add(name,id,password1);
            cout<<"Successful Registration"<<endl;
            break;
        case 3:
            cout<<"Enter Security Pin (mandatory for librarian): ";
            int n;
            cin>>n;
            if(n==1111){
                database.add(name,id,password1,"LIBRARIAN");
                librariandb.add(name,id,password1);
                cout<<"Successful Registration"<<endl;
            }
            else{
                cout<<"Unsuccessful Registration due to incorrect security pin. Try again."<<endl;
            }
            break;
        default:
            cout<<"Unsuccessful Registration due to wrong number chosen. Try again."<<endl;
            break;
    }
    home(database,profdb,studentdb,librariandb,bookdb);
}

void student_attributes(student &s, book_db& bookdb){
    cout<<"Choose the number according to your requirement:"<<endl;
    cout<<"1. "<<"Display all the books in library."<<endl;
    cout<<"2. "<<"Display all the books issued by you."<<endl;
    cout<<"3. "<<"Issue a book."<<endl;
    cout<<"4. "<<"Book availability - Type book title and author name in capital letters (separated by newline)."<<endl;
    //cout<<"4. "<<"Total fine for all books issued currently."<<endl;
    //cout<<"1. "<<"."<<endl;
    int num;
    string title,author;
    cin>>num;
    switch(num){
        case 1:
            s.display_b(bookdb);
            break;
        case 2:
            s.display_list();
            break;
        case 3:
            cout<<"Title of book : ";
            cin>>title;
            cout<<"Author of book : ";
            cin>>author;
            s.issue(title,author,bookdb);
            break;
        case 4:
            cout<<"Title of book : ";
            cin>>title;
            cout<<"Author of book : ";
            cin>>author;
            if(s.issuable(title,author,bookdb)){
                cout<<"Issuable."<<endl;
            }
            else
                cout<<"Non-Issuable right now."<<endl;
            break;
        default:
            cout<<"You had entered invalid number.";
            break;
    }
    student_attributes(s,bookdb);
}

void prof_attributes(prof &p, book_db& bookdb){
    cout<<"Choose the number according to your requirement:"<<endl;
    cout<<"1. "<<"Display all the books in library."<<endl;
    cout<<"2. "<<"Display all the books issued by you."<<endl;
    cout<<"3. "<<"Issue a book."<<endl;
    cout<<"4. "<<"Book availability - Type book title and author name in capital letters (separated by newline)."<<endl;
    //cout<<"4. "<<"Total fine for all books issued currently."<<endl;
    //cout<<"1. "<<"."<<endl;
    int num;
    string title,author;
    cin>>num;
    switch(num){
        case 1:
            p.display_b(bookdb);
            break;
        case 2:
            p.display_list();
            break;
        case 3:
            cout<<"Title of book : ";
            cin>>title;
            cout<<"Author of book : ";
            cin>>author;
            p.issue(title,author,bookdb);
            break;
        case 4:
            cout<<"Title of book : ";
            cin>>title;
            cout<<"Author of book : ";
            cin>>author;
            if(p.issuable(title,author,bookdb)){
                cout<<"Issuable."<<endl;
            }
            else
                cout<<"Non-Issuable right now."<<endl;
            break;

        default:
            cout<<"You had entered invalid number.";
            break;
    }
    prof_attributes(p,bookdb);
}

void librarian_attributes(){
    
}



void login(user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb,book_db& bookdb){
    string id,password;
    cout<<"Enter id : ";
    cin>>id;
    if(!database.search(id)){
        cout<<"This ID doesn't exist. Try again or register."<<endl;
        cout<<"Enter 1 for registering, else you'll be redirected to login page again.";
        int num;
        cin>>num;
        if(num==1){
            registration(database,profdb,studentdb,librariandb,bookdb);
            return;
        }
        else{
            login(database,profdb,studentdb,librariandb,bookdb);
            return;
        }
    }
    cout<<"Enter password : ";
    cin>>password;
    trav(database.users,i){
        if((*i).id==id && (*i).password!=password){
            cout<<"Wrong password"<<endl;
            login(database,profdb,studentdb,librariandb,bookdb);
            return;
        }
        if((*i).id==id && (*i).password==password){
            if(i->category=="STUDENT"){
                trav(studentdb.students,j){
                    if(j->id==i->id){
                        student_attributes((*j),bookdb);
                    }
                }
            }
            if(i->category=="PROFESSOR"){
                trav(profdb.profs,j){
                    if(j->id==i->id){
                        prof_attributes((*j),bookdb);
                    }
                }
            }
            if(i->category=="LIBRARIAN"){
                librarian_attributes();
            }
        }
    }
}



void home(user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb,book_db& bookdb){
    cout<<"LIBRARY MANAGEMENT Home"<<endl;
    cout<<"Please enter the number corresponding to your requirement, eg 1 for login"<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Register as librarian"<<endl;
    cout<<"3. Exit"<<endl;
    int num;
    cin>>num;
    switch(num){
        case 1: 
            login(database,profdb,studentdb,librariandb,bookdb);
            break;
        case 2:
            registration(database,profdb,studentdb,librariandb,bookdb);
            break;
        case 3:
            return;
        default:
            cout<<"You have chosen invalid option. Try again."<<endl;
            home(database,profdb,studentdb,librariandb,bookdb);
            break;
    }
}

int main(){
    user_db database;
    prof_db profdb;
    student_db studentdb;
    librarian_db librariandb;
    book_db bookdb;
    bookdb.add("Mydiary","Samar","420420","XYZ Publishers");
    bookdb.add("ABC","XYZ","1111","New Publishers");
    home(database,profdb,studentdb,librariandb,bookdb);
    return 0;
}