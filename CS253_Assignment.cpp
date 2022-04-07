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

int ceil(int a,int b){
    if(a%b==0)
        return (a/b);
    return (a/b)+1;
}

class Date{
    public:
        int d, m, y;
        ll count_leap(){
            ll year=y;
            if(m<=2)
                year--;
            return year/4 - year/100 + year/400;
        }


};

const int monthDays[12]
    = { 31, 28, 31, 30, 31, 30,
       31, 31, 30, 31, 30, 31 };
 
ll diff(Date dt1, Date dt2){
    ll n1 = dt1.y * 365 + dt1.d;
    fl(i,0,dt1.m)
        n1 += monthDays[i];
    n1 += dt1.count_leap();
    ll n2 = dt2.y * 365 + dt2.d;
    fl(i,0,dt2.m)
        n2 += monthDays[i];
    n2 += dt2.count_leap();
    return n2 - n1;
}

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
        Date issue_date;
        book(string title, string author, string isbn, string publication){
            this->title=title;
            this->author=author;
            this->isbn=isbn;
            this->publication=publication;
            this->issue_date.d=0;
            this->issue_date.m=0;
            this->issue_date.y=0;
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

        void add(string name,string id,string password,string category){
            if(search(id)){
                cout<<"This user has been registered already.";
                return;
            }
            user* u = new user(name,id,password,category);
            users.pb(*u);
        }

        void del(string id){
            trav(users,i){
                if((*i).id==id){
                    users.erase(i);
                    cout<<"User deleted successfully."<<endl;
                    return;
                }
            }
            cout<<"User not present in database"<<endl;
        }

        void update(string id, string name1, string password1, string category){
            trav(users,i){
                if ((*i).id==id){
                    (*i).name=name1;
                    (*i).password=password1;
                    (*i).category=category;
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

        int search(string isbn){
            trav(books, i){
                if ((*i).isbn == isbn)
                    return 1;
            }
            return 0;
        }

        void add(){
            string title, author, isbn, publication;
            cout<<"Enter book title: (use _ instead of space for separation) ";
            cin>>title;
            cout<<"Enter author's name (use _ instead of space for separation): ";
            cin>>author;
            cout<<"Enter isbn (use _ instead of space for separation): ";
            cin>>isbn;
            cout<<"Enter publication name (use _ instead of space for separation): ";
            cin>>publication;
            if (search(isbn)){
                cout<<"Book already present in library."<<endl;
                return;
            }
            book* b=new book(title,author,isbn,publication);
            books.pb(*b);
            cout<<"Book added."<<endl;
        }

        void delete_user_from_map(string id){
            trav(data,i){
                if(i->second==id){
                    data.erase(i->first);
                    trav(books,j){
                        if(j->isbn==i->first){
                            j->issue_date.d=0;
                            j->issue_date.m=0;
                            j->issue_date.y=0;
                        }
                    }
                    return;
                }
            }
        }

        void del(){
            cout<<"Find the book you want to delete."<<endl;
            display_b();
            string isbn;
            cout<<"Enter isbn (use _ instead of space for separation): ";
            cin>>isbn;
            trav(books, i){
                if ((*i).isbn == isbn){
                    books.erase(i);
                    data.erase(isbn);
                    cout<<"Book deleted."<<endl;
                    return;
                }
            }
            cout<<"Book was not in the database."<<endl;
        }

        void update(){
            cout<<"Find the book you want to update."<<endl;
            display_b();
            string isbn;
            cout<<"Enter isbn (use _ instead of space for separation): ";
            cin>>isbn;
            string title1,author1,publication1;
            cout<<"New title (use _ instead of space for separation): ";
            cin>>title1;
            cout<<"New author name (use _ instead of space for separation): ";
            cin>>author1;
            cout<<"New publication (use _ instead of space for separation): ";
            cin>>publication1;
            trav(books, i){
                if ((*i).isbn == isbn){
                    (*i).title == title1;
                    (*i).author == author1;
                    (*i).publication = publication1;
                    cout<<"Book details updated successfully"<<endl;
                    return;
                }
            }
        }       

};

class prof : public user{
    public:
        int fine;
        void display_b(book_db& bookdb){
            int count=1;
            trav(bookdb.books, i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
                count++;
            }
        }
        prof(string name,string id,string password,string category):user(name,id,password,category){
            this->fine=0;
        }
        vector<book> list;
        void display_list(){
            int count=1;
            trav(list,i){
                cout << count << ". " << "Title: " << (*i).title << "   Author: " << (*i).author << "   ISBN: " << (*i).isbn << "   Publication: " << (*i).publication << endl;
                count++;
            }
        }
        void issue(string isbn, book_db& database){
            trav(database.books,i){
                if(i->isbn==isbn && !f(database.data,i->isbn)){
                   
                    count++;
                    cout<<"Enter today's complete date,month and year in numerical form."<<endl;
                    int date,month,year;
                    cout<<"Date (DD format): ";
                    cin>>date;
                    cout<<"Month (MM format): ";
                    cin>>month;
                    cout<<"Year (YYYY format): ";
                    cin>>year;
                    Date* d=new Date;
                    d->d=date;
                    d->m=month;
                    d->y=year;
                    i->issue_date=(*d);
                    list.pb(*i);
                    database.data[(*i).isbn]=id;
                    cout<<"Issued successfully."<<endl;
                    return;
                }
            }
        }
        int issuable(string isbn, book_db& database){
            trav(database.books,i){
                if(i->isbn==isbn && !f(database.data,i->isbn)){
                    return 1;
                }
            }
            return 0;
        }
        void calculate_fine(){
            cout<<"Enter today's complete date,month and year in numerical form."<<endl;
            int date,month,year;
            cout<<"Date (DD format): ";
            cin>>date;
            cout<<"Month (MM format): ";
            cin>>month;
            cout<<"Year (YYYY format): ";
            cin>>year;
            Date* d=new Date;
            d->d=date;
            d->m=month;
            d->y=year;
            Date curr=(*d);
            int amount=0;
            trav(list,i){
                if(diff(i->issue_date,curr)>30){
                    amount+=((diff(i->issue_date,curr)-30)*5);
                }
            }
            fine=amount;
            cout<<"Total fine is Rs "<<fine<<endl;
        }
        void clear_fine_amount(book_db &bookdb){
            fine=0;
            cout<<"Enter today's complete date,month and year in numerical form."<<endl;
            int date,month,year;
            cout<<"Date (DD format): ";
            cin>>date;
            cout<<"Month (MM format): ";
            cin>>month;
            cout<<"Year (YYYY format): ";
            cin>>year;
            Date* d=new Date;
            d->d=date;
            d->m=month;
            d->y=year;
            Date curr=(*d);
            trav(list,i){
                if(diff(i->issue_date,curr)>30){
                    i->issue_date.d=0;
                    i->issue_date.m=0;
                    i->issue_date.y=0;
                    list.erase(i);
                    bookdb.data.erase(i->isbn);
                    break;
                }
            }
            cout<<"Amount cleared"<<endl;
        }

        void return_book(book_db &bookdb){
            string isbn;
            cout<<"Check the book you want to return."<<endl;
            display_list();
            cout<<"Enter book isbn: ";
            cin>>isbn;
            cout<<"Enter today's complete date,month and year in numerical form."<<endl;
            int date,month,year;
            cout<<"Date (DD format): ";
            cin>>date;
            cout<<"Month (MM format): ";
            cin>>month;
            cout<<"Year (YYYY format): ";
            cin>>year;
            Date* d=new Date;
            d->d=date;
            d->m=month;
            d->y=year;
            Date curr=(*d);
            trav(list,i){
                if(i->isbn==isbn){
                    if(diff(i->issue_date,curr)>30){
                        fine-=((diff(i->issue_date,curr)-30)*5);
                    }
                    i->issue_date.d=0;
                    i->issue_date.m=0;
                    i->issue_date.y=0;
                    list.erase(i);
                    bookdb.data.erase(i->isbn);
                    cout<<"Book returned successfully."<<endl;
                    break;
                }
            }

        }

        
};

class student : public user{
    public:
        int fine;
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
                count++;
            }
        }
        student(string name,string id,string password,string category):user(name,id,password,category){
            this->fine=0;
        }
        void limit(){
            cout<< "You can issue only 5 books at max!"<<endl;
        }

        void issue(string isbn, book_db& database){
            trav(database.books,i){
                if(i->isbn==isbn && !f(database.data,i->isbn)){
                    if(count>=5){
                        limit();
                        return;
                    }
                    
                    count++;
                    cout<<"Enter today's complete date,month and year in numerical form."<<endl;
                    int date,month,year;
                    cout<<"Date (DD format): ";
                    cin>>date;
                    cout<<"Month (MM format): ";
                    cin>>month;
                    cout<<"Year (YYYY format): ";
                    cin>>year;
                    Date* d=new Date;
                    d->d=date;
                    d->m=month;
                    d->y=year;
                    i->issue_date=(*d);
                    list.pb(*i);
                    database.data[(*i).isbn]=id;
                    cout<<"Issued successfully."<<endl;
                    return;
                }
            }
        }

        int issuable(string isbn, book_db& database){
            trav(database.books,i){
                if(i->isbn==isbn && !f(database.data,i->isbn)){
                    return 1;
                }
            }
            return 0;
        }
        void calculate_fine(){
            cout<<"Enter today's complete date,month and year in numerical form."<<endl;
            int date,month,year;
            cout<<"Date (DD format): ";
            cin>>date;
            cout<<"Month (MM format): ";
            cin>>month;
            cout<<"Year (YYYY format): ";
            cin>>year;
            Date* d=new Date;
            d->d=date;
            d->m=month;
            d->y=year;
            Date curr=(*d);
            int amount=0;
            trav(list,i){
                if(diff(i->issue_date,curr)>30){
                    amount+=((diff(i->issue_date,curr)-30)*2);
                }
            }
            fine=amount;
            cout<<"Total fine is Rs "<<fine<<endl;
        }
        void clear_fine_amount(book_db &bookdb){
            fine=0;
            cout<<"Enter today's complete date,month and year in numerical form."<<endl;
            int date,month,year;
            cout<<"Date (DD format): ";
            cin>>date;
            cout<<"Month (MM format): ";
            cin>>month;
            cout<<"Year (YYYY format): ";
            cin>>year;
            Date* d=new Date;
            d->d=date;
            d->m=month;
            d->y=year;
            Date curr=(*d);
            trav(list,i){
                if(diff(i->issue_date,curr)>30){
                    i->issue_date.d=0;
                    i->issue_date.m=0;
                    i->issue_date.y=0;
                    list.erase(i);
                    bookdb.data.erase(i->isbn);
                    break;
                }
            }
            cout<<"Amount cleared"<<endl;
        }
        void return_book(book_db &bookdb){
            string isbn;
            cout<<"Check the book you want to return."<<endl;
            display_list();
            cout<<"Enter book isbn: ";
            cin>>isbn;
            cout<<"Enter today's complete date,month and year in numerical form."<<endl;
            int date,month,year;
            cout<<"Date (DD format): ";
            cin>>date;
            cout<<"Month (MM format): ";
            cin>>month;
            cout<<"Year (YYYY format): ";
            cin>>year;
            Date* d=new Date;
            d->d=date;
            d->m=month;
            d->y=year;
            Date curr=(*d);
            trav(list,i){
                if(i->isbn==isbn){
                    if(diff(i->issue_date,curr)>30){
                        fine-=((diff(i->issue_date,curr)-30)*2);
                    }
                    i->issue_date.d=0;
                    i->issue_date.m=0;
                    i->issue_date.y=0;
                    list.erase(i);
                    bookdb.data.erase(i->isbn);
                    cout<<"Book returned successfully."<<endl;
                    break;
                }
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

        void del(string id){
            trav(profs,i){
                if(i->id==id){
                    profs.erase(i);
                    return;
                }
            }
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

        void del(string id){
            trav(students,i){
                if(i->id==id){
                    students.erase(i);
                    return;
                }
            }
        }

};

void registration(user_db &,prof_db &,student_db &);

class librarian : public user{
    public:
        librarian(string name,string id,string password,string category):user(name,id,password,category){}
        void add_book(book_db& bookdb){
            bookdb.add();
        }
        void delete_book(book_db& bookdb){
            bookdb.del();
        }
        void update_book(book_db& bookdb){
            bookdb.update();
        }
        void add_user(user_db &database,prof_db &profdb,student_db &studentdb){
            registration(database,profdb,studentdb);
        }
        void delete_user(user_db& userdb,prof_db &profdb,student_db &studentdb, book_db &bookdb){
            cout<<"Find the user you want to delete."<<endl;
            userdb.display_u();
            string id;
            cout<<"Enter id of the user to be deleted (use _ instead of space for separation): ";
            cin>>id;
            userdb.del(id);
            profdb.del(id);
            studentdb.del(id);
            bookdb.delete_user_from_map(id);
        }
        void update_user(user_db& userdb,prof_db &profdb,student_db &studentdb, book_db &bookdb){
            cout<<"Find the user you want to update."<<endl;
            userdb.display_u();
            string id,name1,password1,category;
            cout<<"Enter id of the user (use _ instead of space for separation): ";
            cin>>id;
            cout<<"New name (use _ instead of space for separation): ";
            cin>>name1;
            cout<<"New password (use _ instead of space for separation): ";
            cin>>password1;
            cout<<"New category (STUDENT or PROFESSOR): ";
            cin>>category;
            userdb.update(id,name1,password1,category);
            profdb.del(id);
            studentdb.del(id);
            if(category=="STUDENT"){
                studentdb.add(name1,id,password1);
                
            }
            if(category=="PROFESSOR"){
                profdb.add(name1,id,password1);
                
            }
            cout<<"User updated successfully."<<endl;
        }
        void display_b(book_db& bookdb){
            bookdb.display_b();
        }
        void display_u(user_db& userdb){
            userdb.display_u();
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

void registration(user_db &database,prof_db &profdb,student_db &studentdb){
    string id,password1,password2,name;
    cout<<"Name (use _ instead of space for separation): ";
    cin>>name;
    cout<<"ID (use _ instead of space for separation): ";
    cin>>id;
    if(database.search(id)){
        cout<<endl<<"ID already exists. Try again."<<endl;
        registration(database,profdb,studentdb);
        return;
    }
    cout<<"Password (use _ instead of space for separation): ";
    cin>>password1;
    cout<<"Confirm Password (use _ instead of space for separation): ";
    cin>>password2;
    if(password1!=password2){
        cout<<endl<<"Passwords don't match. Try again."<<endl;
        registration(database,profdb,studentdb);
        return;
    }
    cout<<"Register as:"<<endl;
    cout<<"1. Student"<<endl;
    cout<<"2. Professor"<<endl;
    cout<<"Write the number of your choice, according to the above list. For example, 1 for Student."<<endl;
        cout<<"Note: Entering any other number will lead to exiting this page."<<endl;
    int num;
    cin>>num;
    cout<<endl;
    switch(num){
        case 1:
            database.add(name,id,password1,"STUDENT");
            studentdb.add(name,id,password1);
            cout<<"Successful Registration"<<endl;
            return;
        case 2:
            database.add(name,id,password1,"PROFESSOR");
            profdb.add(name,id,password1);
            cout<<"Successful Registration"<<endl;
            return;
        default:
            cout<<"Unsuccessful Registration due to wrong number chosen. Try again."<<endl;
            break;
    }
}

void registration_lib(user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb, book_db& bookdb){
    string id,password1,password2,name;
    cout<<"Name (use _ instead of space for separation): ";
    cin>>name;
    cout<<"ID (use _ instead of space for separation): ";
    cin>>id;
    if(database.search(id)){
        cout<<endl<<"ID already exists. Try again."<<endl;
        registration_lib(database,profdb,studentdb,librariandb,bookdb);
        return;
    }
    cout<<"Password (use _ instead of space for separation): ";
    cin>>password1;
    cout<<"Confirm Password (use _ instead of space for separation): ";
    cin>>password2;
    if(password1!=password2){
        cout<<endl<<"Passwords don't match. Try again."<<endl;
        registration_lib(database,profdb,studentdb,librariandb,bookdb);
        return;
    }
    cout<<"1. Register as Librarian"<<endl;
    cout<<"2. Exit"<<endl;
    cout<<"Write the number of your choice, according to the above list. For example, 1 for registration."<<endl;
    int num;
    cin>>num;
    switch(num){
        case 2:
            return;
        case 1:
            cout<<"Enter Security Pin (you need to type 1111, this feature was added just for some confidentiality): ";
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
            cout<<"Unsuccessful Registration due to number chosen being wrong. Try again."<<endl;
            break;
    }
    home(database,profdb,studentdb,librariandb,bookdb);
}

void student_attributes(student &s, user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb,book_db& bookdb){
    cout<<"Choose the number according to your requirement:"<<endl;
    cout<<"1. Display all the books in library."<<endl;
    cout<<"2. Display all the books issued by you."<<endl;
    cout<<"3. Issue a book."<<endl;
    cout<<"4. Book availability (using isbn)."<<endl;
    cout<<"5. Return a book."<<endl;
    cout<<"6. Calculate total fine imposed."<<endl;
    cout<<"7. Clear all dues (fine) and return books with fine imposed."<<endl;
    cout<<"8. "<<"Logout"<<endl;
    //cout<<"4. "<<"Total fine for all books issued currently."<<endl;
    //cout<<"1. "<<"."<<endl;
    int num;
    string isbn;
    cin>>num;
    switch(num){
        case 1:
            s.display_b(bookdb);
            break;
        case 2:
            s.display_list();
            break;
        case 3:
            cout<<"Find the book of your choice."<<endl;
            s.display_b(bookdb);
            cout<<"ISBN of book (use _ instead of space for separation): ";
            cin>>isbn;
            s.issue(isbn,bookdb);
            break;
        case 4:
            cout<<"Find the book of your choice."<<endl;
            s.display_b(bookdb);
            cout<<"ISBN of book (use _ instead of space for separation): ";
            cin>>isbn;
            if(s.issuable(isbn,bookdb)){
                cout<<"Issuable."<<endl;
            }
            else
                cout<<"Non-Issuable right now."<<endl;
            break;
        case 5:
            s.return_book(bookdb);
            break;
        case 6:
            s.calculate_fine();
            break;
        case 7:
            s.clear_fine_amount(bookdb);
            break;
        case 8:
            home(database,profdb,studentdb,librariandb,bookdb);
            return;
        default:
            cout<<"You had entered invalid number.";
            break;
    }
    student_attributes(s,database,profdb,studentdb,librariandb,bookdb);
}

void prof_attributes(prof &p, user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb,book_db& bookdb){
    cout<<"Choose the number according to your requirement:"<<endl;
    cout<<"1. "<<"Display all the books in library."<<endl;
    cout<<"2. "<<"Display all the books issued by you."<<endl;
    cout<<"3. "<<"Issue a book."<<endl;
    cout<<"4. "<<"Book availability (using isbn)."<<endl;
    cout<<"5. Return a book."<<endl;
    cout<<"6. Calculate total fine imposed."<<endl;
    cout<<"7. Clear all dues (fine)."<<endl;
    cout<<"8. "<<"Logout"<<endl;
    //cout<<"4. "<<"Total fine for all books issued currently."<<endl;
    //cout<<"1. "<<"."<<endl;
    int num;
    string isbn;
    cin>>num;
    switch(num){
        case 1:
            p.display_b(bookdb);
            break;
        case 2:
            p.display_list();
            break;
        case 3:
            cout<<"Find the book of your choice."<<endl;
            p.display_b(bookdb);
            cout<<"ISBN of book (use _ instead of space for separation): ";
            cin>>isbn;
            p.issue(isbn,bookdb);
            break;
        case 4:
            cout<<"Find the book of your choice."<<endl;
            p.display_b(bookdb);
            cout<<"ISBN of book (use _ instead of space for separation): ";
            cin>>isbn;
            if(p.issuable(isbn,bookdb)){
                cout<<"Issuable."<<endl;
            }
            else
                cout<<"Non-Issuable right now."<<endl;
            break;
        case 5:
            p.return_book(bookdb);
            break;
        case 6:
            p.calculate_fine();
            break;
        case 7:
            p.clear_fine_amount(bookdb);
            break;
        case 8:
            home(database,profdb,studentdb,librariandb,bookdb);
            return;
        default:
            cout<<"You had entered invalid number."<<endl;
            break;
    }
    prof_attributes(p,database,profdb,studentdb,librariandb,bookdb);
}

void librarian_attributes(librarian &l, user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb,book_db& bookdb){
    cout<<"Choose the number according to your requirement:"<<endl;
    cout<<"1. Add a book."<<endl;
    cout<<"2. Update a book."<<endl;
    cout<<"3. Delete a book."<<endl;
    cout<<"4. Add a user."<<endl;
    cout<<"5. Update a user."<<endl;
    cout<<"6. Delete a user."<<endl;
    cout<<"7. Display all books."<<endl;
    cout<<"8. Display all users."<<endl;
    cout<<"9. Display books issued right now and by whom."<<endl;
    cout<<"10. Display books issued by a specific user."<<endl;
    cout<<"11. Logout."<<endl;
    int num;
    cin>>num;
    string id;
    switch(num){
        case 1:
            l.add_book(bookdb);
            break;
        case 2:
            l.update_book(bookdb);
            break;
        case 3:
            l.delete_book(bookdb);
            break;
        case 4:
            l.add_user(database,profdb,studentdb);
            break;
        case 5:
            l.update_user(database,profdb,studentdb,bookdb);
            break;
        case 6:
            l.delete_user(database,profdb,studentdb,bookdb);
            break;
        case 7:
            l.display_b(bookdb);
            break;
        case 8:
            l.display_u(database);
            break;
        case 9:
            l.user_book_mapping(bookdb,database);
            break;
        case 10:
            cout<<"Find the required user.";
            l.display_u(database);
            cout<<"Enter user's id (use _ instead of space for separation): ";
            cin>>id;
            l.user_book_list(id,bookdb,database);
            break;
        case 11:
            home(database,profdb,studentdb,librariandb,bookdb);
            return;
        default:
            cout<<"You had entered invalid number."<<endl;
            break;
    }
    librarian_attributes(l,database,profdb,studentdb,librariandb,bookdb);
}


void login(user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb,book_db& bookdb){
    string id,password;
    cout<<"Enter id (use _ instead of space for separation): ";
    cin>>id;
    if(!database.search(id)){
        cout<<"This ID doesn't exist. Try again or register."<<endl;
        cout<<"Enter 1 for registering as librarian, else you'll be redirected to login page again.";
        int num;
        cin>>num;
        if(num==1){
            registration_lib(database,profdb,studentdb,librariandb,bookdb);
            return;
        }
        else{
            login(database,profdb,studentdb,librariandb,bookdb);
            return;
        }
    }
    cout<<"Enter password (use _ instead of space for separation): ";
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
                        student_attributes((*j),database,profdb,studentdb,librariandb,bookdb);
                    }
                }
            }
            if(i->category=="PROFESSOR"){
                trav(profdb.profs,j){
                    if(j->id==i->id){
                        prof_attributes((*j),database,profdb,studentdb,librariandb,bookdb);
                    }
                }
            }
            if(i->category=="LIBRARIAN"){
                trav(librariandb.librarians,j){
                    if(j->id==i->id){
                        librarian_attributes((*j),database,profdb,studentdb,librariandb,bookdb);
                    }
                }
            }
        }
    }
}

void home(user_db &database,prof_db &profdb,student_db &studentdb,librarian_db &librariandb,book_db& bookdb){
    cout<<"LIBRARY MANAGEMENT Home"<<endl;
    cout<<"Please enter the number corresponding to your requirement, eg 1 for login"<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Register as Librarian using security pin."<<endl;
    cout<<"3. Exit"<<endl;
    int num;
    cin>>num;
    switch(num){
        case 1:
            login(database,profdb,studentdb,librariandb,bookdb);
            break;
        case 2:
            registration_lib(database,profdb,studentdb,librariandb,bookdb);
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
    book* b;
    b=new book(string("My_diary"),string("Samar"),string("420420"),string("XYZ_Publishers"));
    bookdb.books.pb(*b);
    b=new book(string("ABC"),string("XYZ"),string("1111"),string("New_Publishers"));
    bookdb.books.pb(*b);
    home(database,profdb,studentdb,librariandb,bookdb);
    return 0;
}