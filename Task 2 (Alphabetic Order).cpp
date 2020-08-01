#include<iostream>
#include<cstring>

using namespace std;

struct Movie {
  int id;
  char *title;
  int year;
  Movie* next;
};
Movie *head = NULL;

void add_Movie(int, char*, int);
void remove_Movie(int);
void print();
int& access (int, char *, int);

int main(){
  //Printing empty list
  print();

  //Deleting from empty list
  remove_Movie(1);

  cout << "========== Adding movies =========" << endl;
  //Addition to empty list
  add_Movie(8, "a", 1945); add_Movie(3, "b", 1962); add_Movie(2, "c", 2001);
  add_Movie(1, "d", 1990); add_Movie(5, "e", 1825); add_Movie(7, "f", 1320);
  add_Movie(4, "g", 1991); add_Movie(6, "h", 1998); add_Movie(9, "i", 2000);
  print();

  cout << "========== Adding same movie =========" <<endl;
  //Adding same movie
  add_Movie(1, "d", 1990);

  cout << "========== Deleting movies =========" << endl;
  //Removing head element 
  remove_Movie(7);
  cout << "Printing list without head element " << endl;
  print();

  //Removing tail element
  remove_Movie(2);
  cout << "Printing list without last element" << endl;
  print();

  //removing element from the middle
  remove_Movie(8);
  cout << "Printing list without some middle element" << endl;
  print();
  cout << "Changing name of existing movie using new function" << endl;
  access (5, "o", 1945);
  print();

  cout << "Adding a new movie if ID doesnt already exist in the list else changing the name " << endl << endl;
  access (8, "a", 1945);
  print();

  return 0;
}

void add_Movie(int id, char* title, int year) { 
 Movie *iterate = head;

  //make sure don't repeat an id
 while(iterate != NULL) {
  if(iterate -> id == id) {
    cout << "Cant add another movie with the same id" << endl;   
    return;
  }
  iterate = iterate -> next;
}
  //free memory of temp pointer if no repeats 
delete iterate;

  //continue sorted insert by year
Movie *temp = new Movie;
temp -> id = id;
temp -> year = year;
temp -> title = (char*)(malloc(sizeof(char) * sizeof(title)));
strcpy(temp -> title, title);
temp -> next = NULL;   

Movie *current = new Movie; 
if (head == NULL || head -> year >= temp -> year) { 
  temp -> next = head; 
  head = temp; 
} else { 
  current = head; 
  while (current -> next != NULL && current -> next -> year < temp -> year) current = current -> next; 
  temp -> next = current -> next; 
  current -> next = temp; 
} 

}
//fix removing head element
void remove_Movie(int id) {
  Movie *current= new Movie;
  current = head;
  Movie *prev = new Movie;
  if(head == NULL) {
    cout << "list is empty!" << endl;
    return;
  } 
  else if (current -> next == NULL) {
    delete current;
    head = NULL;
    return;
  }
  else if( current -> id == id && current -> next != NULL){
    head = current -> next;
    delete current;
    return;
  }
  while(current -> id != id) {
    if(current -> next == NULL) {cout << "Movie not found" << endl;
    return;
  }
  else {
    prev = current;
    current = current -> next;
  }
} 
prev -> next = current -> next;
delete current;
}

void print() {
 Movie *current = new Movie;
 current = head;
 if(head == NULL) cout<<"list is empty!"<<endl;
 while(current != NULL) {
  cout << "ID: " << current -> id << " Title: " << current -> title << " Year: " << current -> year << endl;
  current = current -> next; 
}
}

int& access (int id, char * title, int year){

  Movie *ptr= new Movie;
  ptr = head;

  //checks if there is a movie with the same id. if yes then changes name else adds it.
  while(ptr -> next != NULL) {

    if(ptr -> id == id){

      ptr -> title = (char*)(malloc(sizeof(char) * sizeof(title)));
      strcpy(ptr -> title , title );
      cout << "Title changed :)" << endl;
      return ptr -> year ;

    }

    ptr = ptr -> next ;

  }
  ptr = head;

  cout << "Movie not found so we will add it to the list " << endl;
  Movie *temp = new Movie;
  temp -> id = id;
  temp -> year = 2000;
  temp -> title = (char*)(malloc(sizeof(char) * sizeof(title)));
  strcpy(temp -> title, title);
  temp -> next = NULL;   

  Movie *current = new Movie; 
  if (head == NULL || strcmp(head -> title , temp -> title) >= 0) { 
    temp -> next = head; 
    head = temp; 
  } else { 
    current = head; 
    while (current -> next  != NULL && strcmp(current -> next -> title , temp -> title ) < 0 ) current = current -> next; 
    temp -> next = current -> next; 
    current -> next = temp; 
  } 
  return ptr -> year ;
  
}