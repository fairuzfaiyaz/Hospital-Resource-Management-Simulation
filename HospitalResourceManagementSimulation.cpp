// NAME: FAIRUZ FAIYAZ
// ID: 23-54707-3 
// COURSE: DATA STRUCTURE LAB [T]

#include<iostream>
#include<stack> 
// stack header is only used in infixToPostfix billing convertion and evalution
// PatientManagement_Stack is built from scratch
using namespace std;

class PatientManagement_Node { //doubly linked list Node class
public:
    string name; //patient name
    int age; //patient age
    string priorityLevel; // high-medium-low
    string arrivalTime; // HH:MM AM/PM


    //doublyList
    PatientManagement_Node* next;
    PatientManagement_Node* prev;
public:
    //this PatientManagement_Node constructor will set the values, which is called from PatientManager class,
    // while creating object newPatient of PatientManagement_Node class
    PatientManagement_Node(string pName, int pAge, string pPriorityLevel, string pArrivalTime) {
        name = pName;
        age = pAge;
        priorityLevel = pPriorityLevel;
        arrivalTime = pArrivalTime;
        next = prev = nullptr;
    }
};

class PatientManagement_Stack {
private:
    int size = 1000; //i could not use INT_MAX, it was throwing error
public:
    string* patientNameArr;
    int topPatientIdx;
    PatientManagement_Stack() {
        patientNameArr = new string[size];
        topPatientIdx = -1;
    }

    void pushPatientName(string pName) {
        if (topPatientIdx == size - 1)
        {
            cout << "\nHospital stack is full!";

            //im directly returning, and not printing this because user will get notified about this from addPatient(......) function on PatientManager class
            return;
        }
        patientNameArr[++topPatientIdx] = pName;

    }

    void popPatientName() {
        if (topPatientIdx == -1)
        {
            // cout << "Stack is emoty";
            return;
        }
        topPatientIdx--;
    }

    string topPatient() {
        if (topPatientIdx == -1)
        {
            return "";
        }
        return patientNameArr[topPatientIdx];
    }

    bool isEmpty() { //will check if the stack is empty
        return topPatientIdx == -1;
    }

};


class PatientManager { //all the functions of doublyLinkedList are in this class, also undo function  and displayStackDetails of PatientManagement_Stack
private:
    PatientManagement_Node* head;
    PatientManagement_Node* tail;
    PatientManagement_Stack undoLastPatient;

public:
    PatientManager() {
        head = tail = nullptr;
    }
    //its a pushBack() function, it adds elements to the last of linkedlist
    void addPatient(string pName, int pAge, string pPriorityLevel, string pArrivalTime) {
        PatientManagement_Node* newPatient = new PatientManagement_Node(pName, pAge, pPriorityLevel, pArrivalTime);

        if (head == nullptr) {
            head = tail = newPatient;
        }
        else {
            newPatient->prev = tail;
            tail->next = newPatient;
            tail = newPatient;
        }
        undoLastPatient.pushPatientName(pName); //adding to the stack
        cout << "\nPatient " << pName << " added.";
    }
    //popAnyPosition
    void removePatientByName(string name) {
        if (head == nullptr) {
            cout << "\nPatient list is empty! " << name << " cannot be found.";
            return;
        }
        PatientManagement_Node* temp = head;

        while (temp != nullptr)
        {
            if (temp->name == name)
            {
                if (temp == head && temp == tail) //only 1 patient in the list, it is the head and tail
                {
                    head = tail = nullptr;
                }
                else if (temp == head) //removing the head
                {
                    head = head->next;
                    head->prev = nullptr;
                }
                //remove the tail
                else if (temp == tail)
                {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else {
                    //remove from middle popMiddle()
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                cout << "\nPatient " << name << " removed.";
                return;
            }
            temp = temp->next;
        }
        cout << "\nPatient " << name << " not found.";
    }

    void undoLastPatientEntry() {
        if (undoLastPatient.isEmpty())
        {
            cout << "No Patient left to undo !";
            return;
        }
        string lastPatient = undoLastPatient.topPatient();
        undoLastPatient.popPatientName();
        removePatientByName(lastPatient);
        // cout << "Last patient entry " << lastPatient << " removed from Stack";
        // not printing above line, because removePatientByName(!!!) will print it.
    }

    void  displayStackDetails() {
        cout << "\n\nPatient Stack (Top to Bottom):\n";
        for (int i = undoLastPatient.topPatientIdx; i >= 0; i--)
        {
            cout << undoLastPatient.patientNameArr[i] << endl;
        }
    }

    void displayPatientDetail() {
        cout << '\n';
        if (head == nullptr)
        {
            cout << "\nNo Patient to display!";
            return;
        }

        PatientManagement_Node* temp = head;
        cout << "\nPatient Details (LinkedList):\n";
        while (temp != nullptr)
        {
            cout << "Name: " << temp->name << ", Age: " << temp->age << ", Priority Level: " << temp->priorityLevel << ", Arrival Time: " << temp->arrivalTime << endl;
            temp = temp->next;
        }
    }


};

class DoctorNode {//Doctor Allocation (Binary Search Tree)
public:
    int doctorID;
    string name;
    string specialization;
    DoctorNode* left;
    DoctorNode* right;
    DoctorNode(int dDoctorID, string dName, string dSpecialization) {
        doctorID = dDoctorID;
        name = dName;
        specialization = dSpecialization;
        left = right = nullptr;
    }
};

DoctorNode* addDoctor(DoctorNode* root, int dDoctorID, string dName, string dSpecialization) {
    if (root == nullptr) {
        root = new DoctorNode(dDoctorID, dName, dSpecialization);
        cout << "\nDoctor Added: ID: " << root->doctorID << ", Name = " << root->name << ", Specialization = " << root->specialization;
    }
    else if (dDoctorID < root->doctorID) {
        root->left = addDoctor(root->left, dDoctorID, dName, dSpecialization);
    }
    else if (dDoctorID > root->doctorID) {
        root->right = addDoctor(root->right, dDoctorID, dName, dSpecialization);
    }
    else {
        cout << "\nDoctor with ID " << dDoctorID << " already exists!";
    }

    return root;
}

void searchDoctorByID(DoctorNode* root, int dDoctorID) {
    if (root == nullptr)
    {
        cout << "Doctor ID = " << dDoctorID << " not found!" << endl;

        return;
    }
    else if (root->doctorID == dDoctorID) {
        cout << "Doctor Found: ID: " << root->doctorID << ", Name = " << root->name << ", Specialization = " << root->specialization << endl;
    }
    else if (dDoctorID < root->doctorID)
    {
        searchDoctorByID(root->left, dDoctorID);
    }
    else if (dDoctorID > root->doctorID)
    {
        searchDoctorByID(root->right, dDoctorID);
    }

}

void displayDoctorsInOrder(DoctorNode* root) {
    if (root == nullptr)
    {
        return;
    }
    displayDoctorsInOrder(root->left);
    cout << "\nID: " << root->doctorID << ", " << root->name << ", " << root->specialization;
    displayDoctorsInOrder(root->right);
}

//Requirment 5. . Hospital Department Map (Graph – Adjacency List) 

int size = 50;
string departments[50];
int departmentCount = 0;
int adjList[50][50] = { 0 };
int edgeCount[50] = { 0 };


int getDepartmentIndex(string deptName) {
    for (int i = 0; i < departmentCount; ++i) {
        if (departments[i] == deptName)
            return i;
    }
    departments[departmentCount] = deptName;
    return departmentCount++;
}

void addDepartmentEdge(string from, string to) {
    int u = getDepartmentIndex(from);
    int v = getDepartmentIndex(to);
    adjList[u][edgeCount[u]++] = v;
}

void DisplayAdjacencyList() {
    for (int i = 0; i < departmentCount; ++i) {
        cout << departments[i] << " -> ";
        for (int j = 0; j < edgeCount[i]; ++j) {
            cout << departments[adjList[i][j]];
            if (j != edgeCount[i] - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

//Requirment 6. Billing System (Infix to Postfix Conversion & Evaluation)
int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '+' || op == '-')
    {
        return 1;
    }
    else {
        return -1;
    }
}

string billingExp_infixToPostfix(string infix) {
    stack<char> billStack;
    string postfixResult = "";
    string number = "";

    for (char c : infix) {
        if (isdigit(c)) {
            number += c; // Build the full number
        }
        else if (c == ' ') {
            continue;
        }
        else {
            if (!number.empty()) {
                postfixResult += number + " ";
                number = "";
            }

            if (c == '(') {
                billStack.push(c);
            }
            else if (c == ')') {
                while (!billStack.empty() && billStack.top() != '(') {
                    postfixResult += billStack.top();
                    postfixResult += " ";
                    billStack.pop();
                }
                if (!billStack.empty()) {

                    billStack.pop();
                } // remove '('
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
                while (!billStack.empty() && precedence(billStack.top()) >= precedence(c)) {
                    postfixResult += billStack.top();
                    postfixResult += " ";
                    billStack.pop();
                }
                billStack.push(c);
            }
        }
    }

    if (!number.empty()) {
        postfixResult += number + " ";
    }

    while (!billStack.empty()) {
        postfixResult += billStack.top();
        postfixResult += " ";
        billStack.pop();
    }

    return postfixResult;
}


float evaluatePostfixExpression(string postfixExpression) {
    stack<float> billEvalStack;
    string currentDigit = "";
    for (int i = 0; i < postfixExpression.length();++i)
    {
        char temp = postfixExpression[i];
        if (temp == ' ') {
            if (!currentDigit.empty()) {
                billEvalStack.push(stof(currentDigit)); //string to number
                currentDigit = "";//currentDigit resetting it to clear it
            }
            continue;
        }

        if (isdigit(temp) || temp == '.') {
            currentDigit += temp;
        }
        else if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^')
        {
            if (!currentDigit.empty())
            {
                billEvalStack.push(stof(currentDigit));
            }

            float secondOperand = billEvalStack.top();
            billEvalStack.pop();

            float firstOperand = billEvalStack.top();
            billEvalStack.pop();

            float operationResult = 0;

            switch (temp)
            {
            case '+':
                operationResult = firstOperand + secondOperand;
                break;
            case '-':
                operationResult = firstOperand - secondOperand;
                break;
            case '*':
                operationResult = firstOperand * secondOperand;
                break;
            case '/':
                operationResult = firstOperand / secondOperand;
                break;
            case '^':
                operationResult = 1;
                for (int i = 0; i < secondOperand; ++i)
                {
                    operationResult *= firstOperand;
                }
                break;

            default:
                break;
            }
            billEvalStack.push(operationResult);
        }
    }
    if (!currentDigit.empty())
    {
        billEvalStack.push(stof(currentDigit));
    }
    return billEvalStack.top();
}




void calculateBill(string infixExpression) {
    cout << "\nBill Expression:" << infixExpression;
    string postfixExpression = billingExp_infixToPostfix(infixExpression);
    cout << "\nPostfix: " << postfixExpression;
    cout << "\nFinal Bill Amount: " << evaluatePostfixExpression(postfixExpression);
}

int main() {
    PatientManager PatientManagement;
    /*
    REQUIREMENTS NO.1 -> Patient Management (Doubly Linked List)
    • Add new patients at the end of the list.
    • Remove a specific patient by name.
    • Display all patients currently in the list in forward order.
    */

    cout << "\nAdding Patients (LinkedList & Stack)\n";
    cout << "____________________________________\n";
    PatientManagement.addPatient("Fairuz", 20, "High", "10:17 AM");
    PatientManagement.addPatient("Faiyaz", 22, "Low", "8:41 PM");
    PatientManagement.addPatient("Nabil", 27, "Medium", "11:32 AM");
    PatientManagement.addPatient("Saif", 15, "Low", "12:49 PM");
    PatientManagement.addPatient("Tahmid", 32, "High", "12:36 AM");
    PatientManagement.addPatient("Riyad", 17, "Low", "6:57 AM");
    PatientManagement.addPatient("Korim", 42, "Medium", "4:59 AM");
    PatientManagement.displayPatientDetail();

    cout << "\nRemoving Patients by name (Only from LinkedList)\n";
    cout << "________________________________________________\n";

    PatientManagement.removePatientByName("Fairuz");
    PatientManagement.removePatientByName("Nabil");
    PatientManagement.removePatientByName("Saif");
    PatientManagement.removePatientByName("Fairuz");// NOT IN THE PATIENT LIST, it was poped first
    PatientManagement.displayPatientDetail();


    //REQUIRMENT 3 -> Undo Operation (Stack)
    // Sir, i faced a problem. when i add patients info to the linked list.
    // their names are added to the stack at the same time. but when i remove 
    // patients info by name from the linked list, their name in the stack doesnt get removed. 
    // -> we know that STACK operates on the principle of Last-In, First-Out (LIFO)
    // -> so if i remove a node and its data from the patient linkedlist, its not possible to
    //    remove them from the STACK, because it can pop data from the top only

    // I IMPLEMENTED A STACK SYSTEM, WHERE IF I POP THE topPatient. IT WILL REMOVE DATA FROM THE DOUBLY LIST TOO.
    // but if i removed patients from DLL it will stay in the stack
    // this is my logic behind UNDO OPERATION (STACK)

    cout << "\nStack before UNDO Operation";
    cout << "\n___________________________";

    PatientManagement.displayStackDetails();
    cout << "\nStack after UNDO Operation";
    cout << "\n__________________________\n";

    PatientManagement.undoLastPatientEntry();
    PatientManagement.undoLastPatientEntry();
    PatientManagement.undoLastPatientEntry();
    PatientManagement.displayStackDetails();


    cout << "\nUNDO Operation removed entries from both Stack and DoublyLinkedList";
    cout << "\n___________________________________________________________________";
    PatientManagement.displayPatientDetail(); //undo stack removed nodes from the DLL succesfully


    //REQUIRMENT 4 -> Doctor Allocation (Binary Search Tree)
    cout << "\nAdding Doctors to Binary Search Tree:\n";
    cout << "_____________________________________\n";

    DoctorNode* root = nullptr;
    root = addDoctor(nullptr, 101, "Dr. Hanif", "Neurology");
    // addDoctor(root, 101, "Dr. Hanif", "Neurology");
    addDoctor(root, 192, "Dr. Gazi", "Monology");
    addDoctor(root, 167, "Dr. Kudan", "Cardiology");
    addDoctor(root, 109, "Dr. Zarif", "Orthology");
    addDoctor(root, 119, "Dr. Jhon", "Dermology");
    addDoctor(root, 152, "Dr. Liyan", "Oncology");

    cout << "\n\nSearching Doctors by ID";
    cout << "\n_______________________\n\n";
    searchDoctorByID(root, 119);
    searchDoctorByID(root, 128);
    searchDoctorByID(root, 101);
    cout << "\nDoctors (In-Order Traversal by ID)";
    cout << "\n__________________________________\n";

    displayDoctorsInOrder(root);

    //Requirment 5. . Hospital Department Map (Graph – Adjacency List) 
    addDepartmentEdge("ICU", "Emergency");
    addDepartmentEdge("ICU", "GeneralWard");
    addDepartmentEdge("Emergency", "OPD");
    addDepartmentEdge("GeneralWard", "OPD");
    cout << "\n\nDepartment Connections\n";
    cout << "______________________\n\n";
    DisplayAdjacencyList();

    //Requirment 6. Billing System (Infix to Postfix Conversion & Evaluation)
    cout << "\nBilling Calculation";
    cout << "\n___________________\n";
    calculateBill("(200 + 3 * 150) - 50");

    return 0;
}