#include <iostream>
#include <string>
using namespace std;

class Movie {
	public:
    int id;
    string name;
    string genre;
    int duration;
    Movie* next;

    Movie(int Id,string n,string g,int d){
    	id=Id;
    	name=n;
    	genre=g;
    	duration=d;
    	next=NULL;
	}
};

class ManageMovies {
public:
    Movie* head;
    ManageMovies(){
    	head=NULL;
	}

    Movie* findMovie(int id) {
        Movie* temp = head;
        while (temp != NULL) {
            if (temp->id == id)
                return temp;
            temp = temp->next;
        }
        return NULL;
    }

    void addMovie(int id, string name, string genre, int duration) {
        Movie* newMovie = new Movie(id, name, genre, duration);
        if (head==NULL) {
            head = newMovie;
        } else {
            Movie* temp = head;
            while (temp->next!=NULL) {
                temp = temp->next;
            }
            temp->next = newMovie;
        }
    }

    void editMovie(int id, string newName, string newGenre, int newDuration) {
        Movie* movie;
            movie->name = newName;
            movie->genre = newGenre;
            movie->duration = newDuration;
            
    }

    void deleteMovie(int id) {
        if (head==NULL) {
            cout << "No movies to delete.\n\n";
            return;
        }

        if (head->id == id) {
            Movie* temp = head;
            head = head->next;
            delete temp;
            cout << "Movie deleted successfully!\n\n";
            return;
        }

        Movie* temp = head;
        while (temp->next && temp->next->id != id) {
           temp = temp->next;
        }

        if (temp->next!=NULL) {
            Movie* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Movie deleted successfully!\n\n";
        } else {
            cout << "Movie with ID " << id << " not found.\n\n";
        }
    }

    void searchMovie(int id) {
        Movie* movie;
        if (movie = findMovie(id)) {
            cout << "Movie Found :\n";
            cout << "ID: " << movie->id << "\nName: " << movie->name
                 << "\nGenre: " << movie->genre << "\nDuration: " << movie->duration << " mins\n\n";
        } else {
            cout << "Movie with ID " << id << " not found.\n\n";
        }
    }

    
    void displayMovies() {
        if (head==NULL) {
            cout << "No movies available.\n\n";
            return;
        }
        cout << "Movies List:\n";
        Movie* temp = head;
        while (temp!=NULL) {
            cout << "ID: " << temp->id << "\nName: " << temp->name
                 << "\nGenre: " << temp->genre << "\nDuration: " << temp->duration << " mins\n\n";
            temp = temp->next;
        }
    }
};

class Seat {
	public:
    int seatNumber;
    Seat* next;

    Seat(int num) {
    	seatNumber=num;
    	next=NULL;
	}
};


class SeatBooking {
private:
    Seat* front; 
    Seat* rear;  
    int totalSeats;          
    bool* seatAvailability; 

public:
  
    SeatBooking(int seats) {
    front = NULL;
    rear = NULL;
    totalSeats = seats;


    seatAvailability = new bool[totalSeats + 1];

   
    for (int i = 1; i <= totalSeats; i++) {
        seatAvailability[i] = true;
    }
}

    ~SeatBooking() {
        delete[] seatAvailability;
        while (front==NULL) {
            Seat* temp = front;
            front = front->next;
            delete temp;
        }
    }

   
    void checkSeatAvailability() {
        cout << "Available Seats: ";
        bool found = false;
        for (int i = 1; i <= totalSeats; i++) {
            if (seatAvailability[i]) {
                cout << i << " ";
                found = true;
            }
        }
        if (found==false)
		 cout << "No available seat\n ";
        cout << endl;
    }

    
    void reserveSeat(int seatNumber) {
        if (seatNumber < 1 || seatNumber > totalSeats) {
            cout << "Invalid seat number. Please choose a seat between 1 and " << totalSeats << ".\n\n";
            return;
        }

        if (seatAvailability[seatNumber]==false) {
            cout << "Seat " << seatNumber << " is already booked.\n\n";
            return;
        }

        seatAvailability[seatNumber] = false;

        Seat* newSeat = new Seat(seatNumber);
        if (rear==NULL) {
            front = rear = newSeat;
        } else {
            rear->next = newSeat;
            rear = newSeat;
        }

        cout << "Seat " << seatNumber << " reserved successfully.\n\n";
    }

    void cancelBooking(int seatNumber) {
        if (seatNumber < 1 || seatNumber > totalSeats) {
            cout << "Invalid seat number. Please choose a seat between 1 and " << totalSeats << ".\n\n";
            return;
        }

        if (seatAvailability[seatNumber]==true) {
            cout << "Seat " << seatNumber << " is not currently booked.\n\n";
            return;
        }

        seatAvailability[seatNumber] = true;

    
        Seat* temp = front;
        Seat* prev =NULL;

        while (temp && temp->seatNumber != seatNumber) {
            prev = temp;
            temp = temp->next;
        }

        if (temp!=NULL) {
            if (prev!=NULL) {
                prev->next = temp->next;
            } else {
                front = temp->next;
            }

            if (temp == rear) {
                rear = prev;
            }

            delete temp;
            cout << "Booking for Seat " << seatNumber << " canceled successfully.\n\n";
        } else {
            cout << "Seat " << seatNumber << " not found in booked queue.\n\n";
        }
    }

    void viewBookedSeats() {
        if (front==NULL) {
            cout << "No seats are currently booked.\n\n";
            return;
        }

        cout << "Booked Seats: ";
        Seat* temp = front;
        while (temp!=NULL) {
            cout << temp->seatNumber << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class User {
	public:
    string username;
    string password;
    string profileInfo; 
    User* next;

    User(string uname, string pwd, string profile) {
     username=uname;
     password=pwd;
     profileInfo=profile; 
     next=NULL;
	}
};


class UserManagement {
private:
    User* head; 

public:
    
    UserManagement(){
    	head=NULL;
	}

  
    void registerUser(string username, string password, string profile) {
        User* newUser = new User(username, password, profile);
        newUser->next = head;  
        head = newUser;
    }

    bool loginUser(string username, string password) {
        User* temp = head;
        while (temp != NULL ){
            if (temp->username == username && temp->password == password) {
                cout << "Login successful for user: " << username << endl;
                return true;  
            }
            temp = temp->next;
        }
        cout << "Error: Invalid username or password." << endl;
        return false;  
    }

 
    void updateUserProfile(string username, string newProfileInfo) {
        User* temp = head;
        while (temp!=NULL) {
            if (temp->username == username) {
                temp->profileInfo = newProfileInfo;
                cout << "Profile updated successfully for user: " << username << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Error: User '" << username << "' not found.\n";
    }

  
    void displayUsers() {
        if (head==NULL) {
            cout << "No users registered.\n";
            return;
        }

        cout << "Registered Users:\n";
        User* temp = head;
        while (temp!=NULL) {
            cout << "Username: " << temp->username 
                 << ", Profile Info: " << temp->profileInfo << "\n";
            temp = temp->next;
        }
    }

    ~UserManagement() {
        while (head!=NULL) {
            User* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Payment {
	public:
    string username;
    double amount;
    string transactionType; 
    int bookingId;
    Payment* next;         

    Payment(string user, double amt, string type, int id){
        username=user;
	    amount=amt;
		transactionType=type;
	    bookingId=id;
		 next=NULL; 
		 }
};

class PaymentStack {
private:
    Payment* top;

public:
    
    PaymentStack() {
    	top=NULL;
	}

 
    ~PaymentStack() {
        while (top!=NULL) {
            Payment* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(string username, double amount, string transactionType, int bookingId) {
        Payment* newPayment = new Payment(username, amount, transactionType, bookingId);
        newPayment->next = top;
        top = newPayment;
        cout << transactionType << " of $" << amount << " for Booking ID: " << bookingId << " processed for user: " << username << ".\n";
    }

    Payment* pop() {
        if (top==NULL) {
            cout << "No transactions available.\n";
            return NULL;
        }

        Payment* temp = top;
        top = top->next;
        return temp; 
    }

    Payment* peek() {
        return top;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void displayTransactions() {
        if (isEmpty()) {
            cout << "No transactions to display.\n";
            return;
        }

        cout << "\n--- Transaction History ---\n";
        Payment* temp = top;
        while (temp!=NULL) {
            cout << "User: " << temp->username
                 << ", Type: " << temp->transactionType
                 << ", Amount: $" << temp->amount
                 << ", Booking ID: " << temp->bookingId << "\n";
            temp = temp->next;
        }
        cout << "----------------------------\n";
    }
};

class PaymentProcessing {
private:
    PaymentStack transactions; 

public:
    
    void processPayment(string username, double amount, int bookingId) {
        transactions.push(username, amount, "Payment", bookingId);
    }

    void generateReceipt() {
        Payment* lastTransaction = transactions.peek();
        if (lastTransaction==NULL) {
            cout << "No transactions available to generate a receipt.\n";
            return;
        }

        cout << "\n--- Payment Receipt ---\n";
        cout << "User: " << lastTransaction->username << "\n";
        cout << "Transaction Type: " << lastTransaction->transactionType << "\n";
        cout << "Amount: $" << lastTransaction->amount << "\n";
        cout << "Booking ID: " << lastTransaction->bookingId << "\n";
        cout << "-----------------------\n";
    }

  
    void processRefund(int bookingId) {
        if (transactions.isEmpty()) {
            cout << "No transactions available for refund.\n";
            return;
        }

        PaymentStack tempStack; 
        bool refundProcessed = false;

      
        while (!transactions.isEmpty()) {
            Payment* current = transactions.pop();
            if (current->bookingId == bookingId && current->transactionType == "Payment") {
                // Refund the payment
                cout << "Refund of $" << current->amount << " processed for user: " << current->username
                     << ", Booking ID: " << bookingId << "\n";
                transactions.push(current->username, current->amount, "Refund", bookingId); // Add refund record
                refundProcessed = true;
                delete current;
                break;
            } else {
                tempStack.push(current->username, current->amount, current->transactionType, current->bookingId);
                delete current;
            }
        }

       
        while (!tempStack.isEmpty()) {
            Payment* tempTransaction = tempStack.pop();
            transactions.push(tempTransaction->username, tempTransaction->amount, tempTransaction->transactionType, tempTransaction->bookingId);
            delete tempTransaction;
        }

        if (refundProcessed==false) {
            cout << "No matching payment found for Booking ID: " << bookingId << "\n";
        }
    }

    void viewTransactions() {
        transactions.displayTransactions();
    }
};

class Schedule {
	public:
    int scheduleId;        
    string movieName;      
    string showTime;       
    Schedule* next;        
 
    Schedule(int id, string name, string time){
    	scheduleId=id;
    	movieName=name;
    	showTime=time;
    	next=NULL;
	}

};

class ManageSchedule {
private:
    Schedule* head; 

public:

    ManageSchedule() {
    	head=NULL;
	}

   
    void addSchedule(int scheduleId, string movieName, string showTime) {
        
        Schedule* newSchedule = new Schedule(scheduleId, movieName, showTime);

        if (!head) {
            head = newSchedule;
        } else {
     
            Schedule* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newSchedule;
        }

    
    }


    void editSchedule(int scheduleId, string newMovieName, string newShowTime) {
        Schedule* temp = head;

        while (temp) {
            if (temp->scheduleId == scheduleId) {
                temp->movieName = newMovieName;
                temp->showTime = newShowTime;
                cout << "Schedule updated: " << newMovieName << " at " << newShowTime << "\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Schedule with ID " << scheduleId << " not found.\n";
    }

    void deleteSchedule(int scheduleId) {
        if (!head) {
            cout << "No schedules available to delete.\n";
            return;
        }

        if (head->scheduleId == scheduleId) {
            Schedule* temp = head;
            head = head->next;
            delete temp;
            cout << "Schedule with ID " << scheduleId << " deleted.\n";
            return;
        }

        Schedule* temp = head;
        while (temp->next) {
            if (temp->next->scheduleId == scheduleId) {
                Schedule* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "Schedule with ID " << scheduleId << " deleted.\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Schedule with ID " << scheduleId << " not found.\n";
    }

    void viewSchedules() {
        if (!head) {
            cout << "No schedules available.\n";
            return;
        }

        cout << "Movie Schedules:\n";
        Schedule* temp = head;
        while (temp) {
            cout << "ID: " << temp->scheduleId
                 << ", Movie: " << temp->movieName
                 << ", Show Time: " << temp->showTime << "\n";
            temp = temp->next;
        }
    }

    ~ManageSchedule() {
        while (head) {
            Schedule* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    
    ManageMovies movieManager;
    ManageSchedule scheduleManager;
    PaymentProcessing paymentManage;
    SeatBooking seatBooking(10);
    movieManager.addMovie(1, "Inception", "Sci-Fi", 148);
    movieManager.addMovie(2, "The Dark Knight", "Action", 152);
    movieManager.addMovie(3, "The Smile", "Horror", 169);
    movieManager.addMovie(4, "Interstellar", "Sci-Fi", 169);
    movieManager.addMovie(5, "The Fault in Our Stars", "Sci-Fi", 169);
    scheduleManager.addSchedule(101,"Inception","3:00pm");
    scheduleManager.addSchedule(102,"The Dark Knight","6:00pm");
    scheduleManager.addSchedule(103,"The Smile","9:00pm");
    scheduleManager.addSchedule(104,"Interstellar","11:00am");
    scheduleManager.addSchedule(105,"The Fault in Our Stars","2:00pm");

string m,g,nm,ng;
int d,upId,nd,sId,dId;
int n=5;
int no=n+1;

    int choicee;
    cout << " ******************* Welcome To Cinema Booking System ******************" << endl;
    cout << "LOGIN IN AS: " << endl;
    cout << "1- Admin                  2- User" << endl;
    cout << "Press 1 or 2  " << endl;
    cin >> choicee;

    string username, password;
    bool loginSuccess = false;
    bool isAdmin = false;  

    while (!loginSuccess) {
        switch (choicee) {
            case 1: {
                
                cout << "Admin Login: " << endl;
                while (!loginSuccess) {
                    cout << "Enter admin username: ";
                    cin >> username;
                    cout << "Enter admin password: ";
                    cin >> password;
                    if ((username == "manager") && password == "admin123") {
                        loginSuccess = true;
                        isAdmin = true;
                        cout << "Welcome Admin: " << username << endl;
                    } else {
                        cout << "Invalid admin username or password. Please try again." << endl;
                    }
                }
                break;
            }
            case 2: {
                cout << "User Login: " << endl;
                while (!loginSuccess) {
                    cout << "Enter user username: ";
                    cin >> username;
                    cout << "Enter user password: ";
                    cin >> password;

                    if (username == "john_doe" && password == "password123") {
                        loginSuccess = true;
                        isAdmin = false;
                        cout << "Welcome User: " << username << endl;
while (true) {
        int userChoice;
        cout << "\nUser Menu:\n";
        cout << "1. View Movies\n2. View Movie Timings\n3. Seat Booking\n4. Payment\n5.Logout\n";
        cout << "Choose an option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                movieManager.displayMovies();
                break;
            case 2:
                cout << "Movie Timings:\n";
                scheduleManager.viewSchedules();
                break;
            case 3: {
                int movieId;
                movieManager.displayMovies();
                cout << "Enter the Movie ID to book a seat: ";
                cin >> movieId;

                Movie* selectedMovie = movieManager.findMovie(movieId);
                if (selectedMovie) {
                    cout << "\nSelected Movie:\n";
                    cout << "Name: " << selectedMovie->name << ", Genre: " << selectedMovie->genre
                         << ", Duration: " << selectedMovie->duration << " mins\n";

                    seatBooking.viewBookedSeats();
                    cout << "Available Seats 1 2 3 4 5 6 7 8 9 10 "<<endl;
                    cout << "Enter seat number to book: ";
                    int seatNumber;
                    cin >> seatNumber;
                    seatBooking.reserveSeat(seatNumber);
                    cout << "Ticket Price: $10\n";
                    cout << "Enter your name: ";
                    string userName;
                    cin >> userName;
                    cout << "Payment of $10 received from " << userName << ".\n";
                    cout << "Thank you for your purchase!\n";
                } else {
                    cout << "Invalid Movie ID.\n";
                }
                break;
            }
            case 4: {
                double amountDue = 10.00; 
                double paymentAmount;
                cout << "Payment Menu\n";
                cout << "Your total amount due: $" << amountDue << endl;
                cout << "Enter payment amount: $";
                cin >> paymentAmount;

                if (paymentAmount >= amountDue) {
                    double change = paymentAmount - amountDue;
                    cout << "Payment successful. Change: $" << change << endl;
                    paymentManage.generateReceipt();
                } else {
                    cout << "Insufficient payment. Please pay at least $" << amountDue << ".\n";
                }
                break;
            }
            case 5:
                cout << "Logging out... Goodbye!\n";
                return 0; 
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
                        
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
                cout << "Press 1 for Admin or 2 for User: ";
                cin >> choicee;
        }
    }
    
    if (isAdmin) {
        int adminChoice;
        while (true) {
            cout << "Here is the menu of Cinema Booking System: " << endl;
            cout << "\n1. Manage Movies\n2. Manage Schedule\n3. Exit\n";
            cout << "Choose an option: ";
            cin >> adminChoice;

            switch (adminChoice) {

                case 1: {
                    int movieChoice;
                    while(true){
                    cout << "Manage Movies Menu: " << endl;
                    cout << "1. Add Movie\n2. Update Movie\n3. Search Movie\n4. Delete Movie\n5. Display Movies\n6. Back to Main Menu" << endl;
                    cout << "Choose an option: ";
                    cin >> movieChoice;

                    switch (movieChoice) {
                        case 1:
                        	cout<<"Enter name of movie "<<endl;
                        	cin>>m;
                        	cout<<"Enter genere of movie "<<endl;
                        	cin>>g;
                        	cout<<"Enter duration of movie "<<endl;
                        	cin>>d;
                        	movieManager.addMovie(no, m, g, d);
                        	 cout << "Movie added successfully!\n\n";
                            movieManager.displayMovies();
                            break;
                        case 2:
                            cout<<"Enter ID of movie you want to update "<<endl;
                        	cin>>upId;
                        	Movie*movies;
                        	if (movies=movieManager.findMovie(upId)) {
                        		cout<<"Enter name of movie "<<endl;
                        	cin>>nm;
                        	cout<<"Enter genere of movie "<<endl;
                        	cin>>ng;
                        	cout<<"Enter duration of movie "<<endl;
                        	cin>>nd;
                        	movieManager.editMovie( upId, nm, ng, nd);
                        	cout << "Movie details updated successfully!\n\n";
        } else {
            cout << "Movie with ID " << upId << " not found.\n\n";
        }
                            movieManager.displayMovies();
                            break;
                        case 3:
                             cout << "Enter the id of the movie to search: ";
    
    cin >> sId;
   movieManager.searchMovie(sId);
                            break;
                        case 4:
                             cout << "Enter the id of the movie to delete: ";
    
    cin >> dId;
   movieManager.deleteMovie(dId);
                            break;
                            case 5:
                            {
                            	movieManager.displayMovies();
                            	break;
							}
                      
                        	case 6:
                            cout << "Returning to Admin Menu...\n";
                            goto endMovieMenu; 
                        default:
                            cout << "Invalid option. Try again.\n";
                    
                    }
               }
                endMovieMenu:
                    break;
                }
                
                
case 2: {
    int scheduleChoice;
    while (true) {
        cout << "\nManage Schedule Menu: " << endl;
        cout << "1. Add Schedule\n2. Update Schedule\n3. Delete Schedule\n4. View Schedules\n5. Back to Main Menu\n";
        cout << "Choose an option: ";
        cin >> scheduleChoice;

        switch (scheduleChoice) {
            case 1: { 
                int scheduleId;
                string movieName, time;
                cout << "Enter Schedule ID: ";
                cin >> scheduleId;
                cout << "Enter Movie Name: ";
                cin.ignore(); 
                getline(cin, movieName);
                cout << "Enter Show Time (HH:MM): ";
                cin >> time;

                scheduleManager.addSchedule(scheduleId, movieName, time);
                cout << "New schedule added: " << movieName << " at " << time << "\n";
                break;
            }
            case 2: { 
                int scheduleId;
                string newMovieName, newTime;
                cout << "Enter Schedule ID to update: ";
                cin >> scheduleId;
                    cout << "Enter new Movie Name: ";
                    cin.ignore(); 
                    getline(cin, newMovieName);
                    cout << "Enter new Show Time (HH:MM): ";
                    cin >> newTime;

                    scheduleManager.editSchedule(scheduleId, newMovieName, newTime);
               
                break;
            }
            case 3: { 
                int scheduleId;
                cout << "Enter Schedule ID to delete: ";
                cin >> scheduleId;

                scheduleManager.deleteSchedule(scheduleId);
                break;
            }
            case 4: { 
                scheduleManager.viewSchedules();
                break;
            }
            case 5: 
                cout << "Returning to Admin Menu...\n";
                            goto endScheduleMenu; 
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
    endScheduleMenu:
    break;
}
            case 3:
                cout << "Logging out... Goodbye!\n";
                return 0; 
            default:
                cout << "Invalid option. Try again.\n";

}
 
}
}
}
}




