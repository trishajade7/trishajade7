#include <iostream>
#include <iomanip>

using namespace std;

//Global Variable
    const int SIZE = 100;
    string validUsers[SIZE] = {"user1","user2","user3"};
    string validPasswords[SIZE] = {"default","admin","123"};
    int validUsersSize = sizeof(validUsers)/sizeof(validUsers[0]);
    int validPasswordsSize = sizeof(validPasswords)/sizeof(validPasswords[0]);

    //User Details
    string registeredFNames[SIZE] = {"John","Jenny","Jack"};
    string registeredLNames[SIZE] = {"Cruz","Cabrera","Stalk"};
    float accBalance[SIZE] = {580400.00,284241.00,272815.00};
    char correspondingGender [SIZE] = {'M','F','M'};
    int correspondingMM [SIZE] = {5,1,6};
    int correspondingDD [SIZE] = {15,26,13};
    int correspondingYY [SIZE] = {2002,1998,1995};

    int ID; //Use to get the element of a specific array

    //Sports/Games
    string extremeGames[] = {"Skydiving","Base Jumping","Paragliding","Bungee Jumping","Hand Gliding","Wingsuit Flying","Bodyflight","Sky Surfing","Ultralight Aviation"};
    float fees[] = {4000.00,1000.00,2000.00,1000.00,3000.00,3500.00,3000.00,4250.00,5000.00};
    int gameSize = sizeof(extremeGames)/sizeof(extremeGames[0]);
    //Specific availability of each day
    int d21[] = {0,1,-1,3,4,-1,6,7,-1};
    int d22[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    int d23[] = {0,1,-1,3,4,-1,6,7,-1};
    int d24[] = {0,1,2,3,4,5,6,7,8};
    int d25[] = {0,1,2,3,4,5,6,7,8};
    int d26[] = {-1,-1,-1,-1,4,5,6,7,8};
    int d27[] = {0,1,2,3,4,-1,-1,-1,-1};

    int j01[] = {0,1,2,3,4,5,6,7,8};
    int j02[] = {0,1,2,3,4,5,6,7,8};
    int j03[] = {-1,1,-1,3,-1,5,-1,7,-1};
    int j04[] = {0,-1,2,-1,4,-1,6,-1,8};
    int j05[] = {-1,1,-1,3,-1,5,-1,7,-1};

    //Purchase details for Menu 4
    int selectedGames[] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};
    float amountPaidF;
    float initialAmountF;
    int selectedM;
    int selectedD;

    //Promo Code
    string promoCodes[] = {"XjD5S","5k83y","jjAEW","AEQxe","YrXmJ"};
    float codeDeduction[] = {10.0,25.0,30.0,35.0,40.0};
    int codeSize = sizeof(promoCodes)/sizeof(promoCodes[0]);

    //Transaction Method
    string paymentMethod[] = {"GCash","PayMaya","Card","PayPal"};

    //Declaration of Functions
    void RegisterAccount(string fName_,string lName_,string userName_,char gender_,int mm_,int dd_,int yy_);
    void LogInValidator(string userNameAttempt_,string passwordAttempt_);
    void LogIn();

    void DateSelection();
    void DecemberSelection(int day);
    void DateConfirmationDecember(int day_,int e0,int e1,int e2,int e3,int e4,int e5,int e6,int e7,int e8);
    void JanuarySelection(int day);
    void DateConfirmationJanuary(int day_,int e0,int e1,int e2,int e3,int e4,int e5,int e6,int e7,int e8);
    void PromoCode();
    void Transaction(float pay_,float discount_);

    void Report(float amountPaid, int payMode, float discount);
    void Exit();

//#region Menu 1
/* Summary
    The user is allowed to LogIn or Register
    REGISTER means creating new account. User needs to input their last Name and first Name (e.g. Diaz Destiny), Birthdate in mm/dd/yy format (e.g. 4/24/2000),
    Gender (M or F).The user must enter a unique username otherwise the user will not complete the registration and has to enter another username.
    The user is allowed to add password for the new acccount after the username has been validated and is unique.
    LOGIN means to login into an existing account or the newly created account. Entering an invalid username will notify the user that the account
    they tried to login does not exist. If it exist, then the password must match, otherwise the user must try again until it matches
    EXIT means to terminate the program
*/
int main()
{
    char enter;
    cout << "\nWelcome to XTREME WORLD!" << endl;
    cout << "Enter R to Register or Enter L to LogIn (To Exit Please Enter E)" << endl;

    while(!((enter == 'R' || enter == 'r') || (enter == 'L' || enter == 'l')|| (enter == 'E' || enter == 'e')))
    {
        cout << "Please Enter R or L or E: "; cin >> enter;
        if(enter == 'R' || enter == 'r')
        {
            cout << "\nWelcome new user! Please enter all the information needed" << endl;
            string fName,lName,userName;
            char gender;
            int mm,dd,yy;
            cout << "Enter Name" << endl;
            cout << "Last Name: "; cin >> lName;
            cout << "First Name: "; cin >> fName;
            cout << "Enter Birth Date (mm/dd/yy) Please use numbers." << endl;
            cout << "Month: "; cin >> mm;
            cout << "Day: "; cin >> dd;
            cout << "Year: "; cin >> yy;

            //validation for gender
            while(!((gender == 'M' || gender == 'm')||(gender == 'F' || gender == 'f')))
            {
                cout << "M or m for Male | F or f for Female" << endl;
                cout << "Enter Gender: "; cin >> gender;
                if(!((gender == 'M' || gender == 'm')||(gender == 'F' || gender == 'f')))
                    cout << "Please enter a valid character." << endl;
            }

            cout << "Enter Username: "; cin >> userName;
            //The user will be able to add password after the userName is validated

            //pass in the data to RegisterAccount function
            RegisterAccount(fName,lName,userName,gender,mm,dd,yy);

        }else if(enter == 'L' || enter == 'l')
        {
            //Call the LogIn Function
            LogIn();
        }else if(enter == 'E' || enter == 'e')
        {
            //We call the Exit function
            Exit();
        }else
        {
            cout << "\nSorry, please enter a valid character." << endl;
        }
    }
        return 0;
}

void RegisterAccount(string fName_,string lName_,string userName_,char gender_,int mm_,int dd_,int yy_)
{
    //bool for checking registered info
    bool isExisting = true;
    bool allowToReEnter = false;

    //Assigning passed values to new variables
    string userN = userName_;
    string firstN = fName_;
    string lastN = lName_;
    char gender = gender_;
    int month = mm_;
    int day = dd_;
    int year = yy_;

    //password string variable to be added after the validation
    string password;

    /*Summary
        isExisting is set to true, assuming that the input already existed
        Compare every element to the input, if it did not exist then isExisting is false. We can exit the loop
        Otherwise, the user need to input another username */
     while(isExisting)
    {
        for(int i = 0; i < validUsersSize;)
        {
            if(!isExisting){
                i = 0;
                break;
            }

            if(allowToReEnter)
            {
                cout << "Please Enter Another Username" << endl;
                cout << "Enter Another Username: "; cin >> userN;
            }

                if(validUsers[i] != userN)
                {
                    for(int j=i+1;j< validUsersSize;j++)
                    {
                        if(validUsers[j] != userN)
                        {
                            i++;
                                if(j == validUsersSize - 1){
                                    isExisting = false;
                                    allowToReEnter = false;
                                }
                        }else
                        {
                            cout << "\nSorry, " << validUsers[j] << " Already Exist" << endl;
                            i = 0;
                            j=0;
                            isExisting = true;
                            allowToReEnter = true;
                            break;
                        }
                    }
                }else
                {
                    cout << "\nSorry, " << validUsers[i] << " Already Exist" << endl;
                    isExisting = true;
                    allowToReEnter = true;
                    break;
                }
        }
    }

    //After successfully creating new username
    //The new username is Added to the validUserName array
    if(!isExisting)
    {
        for(int i = 0; i < validUsersSize; i++)
        {
            //cout << "[System] Adding UserName..." << endl; //Debugging
            if(validUsers[i] == "")
            {
                //cout << "[System] UserName Added" << endl; //Debugging
                validUsers[i] = userN;
                //Since all the sizes of array are the same. We can use the value of i
                //Then the program will add the additonal info of the user
                registeredFNames[i] = firstN;
                registeredLNames[i] = lastN;
                correspondingGender[i] = gender;
                correspondingMM[i] = month;
                correspondingDD[i] = day;
                correspondingYY[i] = year;
                //For new account, we will just add 120,000 to their balance since we don't have the actual data for their
                //personal bank/account details (the 120,000 is just to a give the user a balance for transaction in  menu3)
                accBalance[i] = 120000.00;
                isExisting = true;
                i = 0;
                break;
            }
        }
    }

    /* Remove comment to view each elements of registered array) /
    cout << "\n--All Valid Users--" << endl;
    for(string x: validUsers)
        cout << x << endl;

    cout << "\n--All Registered First Names" << endl;
    for(string x: registeredFNames)
        cout << x << endl;

    cout << "\n--All Registered Last Names" << endl;
    for(string x: registeredLNames)
        cout << x << endl;

    cout << "\n--All Account Balance--" << endl;
    for(int x: accBalance)
        cout << x << endl;
    //*/


    //Create a Password is required after creating a password
    cout << "Add Password: "; cin >> password;
    for(int i = 0; i < validPasswordsSize; i++)
    {
        if(validPasswords[i] == "")
        {
            validPasswords[i] = password;
            break;
        }
    }

    /* Remove comment to view each elements of the validPasswords array (all valid passwords)/
    cout << "\n--All Valid Passwords--" << endl;
    for(string x: validPasswords)
        cout << x << endl;

    //*/

    //User need to log in after successfully creating a new account
    LogIn();
}

void LogInValidator(string userNameAttempt_,string passwordAttempt_)
{
    //Assigning passed string values to new strings
    string userName = userNameAttempt_;
    string passWord = passwordAttempt_;

    //To check if the ID was found or not
    bool IDfound = false;

    //We will search for valid user name that correspond the username attempt
    while(!IDfound)
    {
        for(int i = 0; i < validUsersSize;)
        {
            if(IDfound)
            {
                i = 0;
                break;
            }

            if(validUsers[i] == userName)
            {
                IDfound = true;
                ID = i;
                break;
            }
            else
            {
                for(int j=i+1;j < validUsersSize; j++)
                {
                    if(validUsers[i] != userName)
                    {
                        i++;
                        if(j == validUsersSize - 1)
                        {
                            cout << "\nSorry but the account you tried to login doesn't exist" << endl;
                            IDfound = false;
                            j =0;
                            i = 0;
                            //RelogIn
                            cout << "Please enter an existing Account" << endl;
                            cout << "Enter Username: "; cin >> userName;
                            cout << "Enter Password: "; cin>> passWord;
                        }
                    }
                    else
                    {
                        ID = i;
                        IDfound = true;
                        break;
                    }
                }
            }
        }
    }

    bool passwordValid = false;
    if(IDfound)
    {
        bool allowPassWordReEnter = false;

        while(!passwordValid)
        {
            if(allowPassWordReEnter)
            {
                cout << "Enter Password: "; cin >> passWord;
                allowPassWordReEnter = false;
            }

            if(validPasswords[ID] == passWord)
            {
                passwordValid = true;
                break;
            }else
            {
                cout << "\nSorry, wrong password please try again." << endl;
                allowPassWordReEnter = true;
                passwordValid = false;
            }
        }


    }

    if(passwordValid)
    {
        cout << "\nWelcome to XTREME WORLD " << registeredFNames[ID] << " " << registeredLNames[ID] << endl;

        /*///
        cout << "---Additional Details---" << endl;
        cout << "Your gender is " << correspondingGender[ID] << endl;
        cout << "Your Birth Date is (mm/dd/yy): " << correspondingMM[ID] << "/" << correspondingDD[ID] << "/" << correspondingYY[ID] << endl;
        //*/

        IDfound = false;
        passwordValid = false;

        //Call DateSelection Function to proceed in scheduling
        DateSelection();
    }
}

void LogIn()
{
    string userNameAttempt, passwordAttempt;

    cout << "\nPlease enter your credentials" << endl;
    cout << "Enter Username: "; cin >> userNameAttempt;
    cout << "Enter Password: "; cin >> passwordAttempt;

    //Pass values to validate
    LogInValidator(userNameAttempt,passwordAttempt);
}
//#endregion

//#region Menu 2
/* Summary
    The user needs to select a month first and then a date of the month. The program is only limited to December and January
    The program holds a specific array for the available games for each day of the month. The more days or month will make the
    program a bigger project. If the user has choosen a schedule that has an empty games, the program will tell the user to choose
    another schedule because it was scheduled for someone.
*/
void DateSelection()
{
    cout << "\nWe are open from December to January Only" << endl;
    cout << "Please Enter your preferred date" << endl;
    cout << "To look for a specific date, please follow the instructions.\n" << endl;

    int m =-1, d = 29;
    while(!(m == 0 || m ==1))
    {
        cout << "Enter 0 for December, 1 for January\nMonth: "; cin >> m;
        if(m == 0)
        {
            selectedM = m;
            while(!(d > 20 && d < 28))
            {
                cout << "What day in December? Choose from 21 to 27" << endl;
                cout << "Enter Day: "; cin >> d;

                if(d > 20 && d < 28)
                {
                    selectedD = d;
                    cout << "\nPLEASE WAIT..... Looking for what is available for December\n" << endl;
                    DecemberSelection(d);
                }else
                {
                     cout << "\nSorry try again! Please Choose a Valid Date" << endl;
                }
            }
        }else if(m == 1)
        {
            selectedM = m;
            while(!(d > 0 && d < 6))
            {
                cout << "What day in January? Choose from 1 to 5" << endl;
                cout << "Enter Day: "; cin >> d;

                if(d > 0 && d < 6)
                {
                    selectedD = d;
                    cout << "\nPLEASE WAIT..... Looking for what is available for January\n" << endl;
                    JanuarySelection(d);
                }else
                {
                    cout << "\nSorry try again! Please Choose a Valid Date" << endl;
                }
            }
        }else
        {
            cout << "\nSorry, Please enter a valid month" << endl;
        }

    }
}

void DecemberSelection(int day_)
{
    int day = day_;

    cout << "For December " << day << " The avaible XTREME Games are:" << endl;
    if(day == 21)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(d21[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationDecember(day,d21[0],d21[1],d21[2],d21[3],d21[4],d21[5],d21[6],d21[7],d21[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 22)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(d22[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationDecember(day,d22[0],d22[1],d22[2],d22[3],d22[4],d22[5],d22[6],d22[7],d22[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 23)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(d23[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationDecember(day,d23[0],d23[1],d23[2],d23[3],d23[4],d23[5],d23[6],d23[7],d23[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 24)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(d24[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationDecember(day,d24[0],d24[1],d24[2],d24[3],d24[4],d24[5],d24[6],d24[7],d24[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 25)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(d25[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationDecember(day,d25[0],d25[1],d25[2],d25[3],d25[4],d25[5],d25[6],d25[7],d25[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }
    }else if(day == 26)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(d26[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationDecember(day,d26[0],d26[1],d26[2],d26[3],d26[4],d26[5],d26[6],d26[7],d26[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 27)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(d27[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationDecember(day,d27[0],d27[1],d27[2],d27[3],d27[4],d27[5],d27[6],d27[7],d27[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }
    }
}

void JanuarySelection(int day_)
{
    int day = day_;

    cout << "For January " << day << " The avaible XTREME Games are:" << endl;
    if(day == 1)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(j01[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationJanuary(day,j01[0],j01[1],j01[2],j01[3],j01[4],j01[5],j01[6],j01[7],j01[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 2)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(j02[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationJanuary(day,j02[0],j02[1],j02[2],j02[3],j02[4],j02[5],j02[6],j02[7],j02[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 3)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(j03[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationJanuary(day,j03[0],j03[1],j03[2],j03[3],j03[4],j03[5],j03[6],j03[7],j03[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 4)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(j04[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationJanuary(day,j04[0],j04[1],j04[2],j04[3],j04[4],j04[5],j04[6],j04[7],j04[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }else if(day == 5)
    {
        int j = 0;
        for(int i = 0; i < gameSize; i++)
        {
            if(j05[i] == -1) //If the int value is -1 it will add j by 1
            {
                j++;
                if(j == gameSize) // if j will equal to arrSize, which means there are no available games
                    break;
            }
        }

        if(j != gameSize)
        {
            cout << "Please Choose from this Available XTREME Games" << endl;
            //Call the function DateConfirmation
            DateConfirmationJanuary(day,j05[0],j05[1],j05[2],j05[3],j05[4],j05[5],j05[6],j05[7],j05[8]);
        }else
        {
            cout << "We are sorry but all of the XTREME Games here is being scheduled to someone else" << endl;
            cout << "Please choose another schedule\n" << endl;
            //Allow the user to pick another schedule
            DateSelection();
        }

    }
}

/* Summary
    After the user picked a schedule, the user has the freedom to choose games from the available schedule multiple times
    as long as the games is available within the choosen date. The user can still select another date by entering 0 (NO)
    to every available games. The passed integer are the element of the games available (the new elements[] is assigned to
    the passed integers). The user can now have the transaction here but it will still be passed to the functions inside
    Menu 3 to process.The internalMod array acts as a modifier. This modifier will update the available games whether the game
    has been choosen or skipped by the user. The DateConfirmationJanuary Function runs the same code but the difference is the month.
*/
void DateConfirmationDecember(int day_,int e0,int e1,int e2,int e3,int e4,int e5,int e6,int e7,int e8)
{
    int elements[9];
    int eSize = sizeof(elements)/sizeof(elements[0]);
    elements[0] = e0;
    elements[1] = e1;
    elements[2] = e2;
    elements[3] = e3;
    elements[4] = e4;
    elements[5] = e5;
    elements[6] = e6;
    elements[7] = e7;
    elements[8] = e8;

    int day = day_;

    int internalMod[eSize] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

    cout << "-----------------------------" << endl;
    for(int i = 0; i < eSize;i++)
    {
        if(elements[i] != -1)
        {
            cout << extremeGames[elements[i]] << endl;
        }
    }
    cout << "-----------------------------\n" << endl;

    //Transaction
    float initialAmount = 0;
    for(int i = 0; i < eSize; i++)
    {
        int r = -1;
        if(elements[i] != -1)
        {
            while(!(r == 0 || r == 1))
            {
                cout << "1 if YES; 0 if NO" << endl;
                cout << "Cost for this XTREME Game: " << fees[elements[i]] << endl;
                cout << "Do you want to try " << extremeGames[elements[i]] << "? ";
                cin >> r;
                if(r == 1)
                {
                    initialAmount += fees[elements[i]];
                    internalMod[elements[i]] = -1;
                    //The program will keep track the transaction that will display in the reporting(Menu 4)
                    selectedGames[elements[i]] = elements[i];
                }else if(r == 0){
                    internalMod[elements[i]] = elements[i];
                    //The program will keep track the transaction that will display in the reporting(Menu 4)
                    selectedGames[elements[i]] = -1;
                }else
                {
                    cout << "Please enter 0 or 1 only" << endl;
                }
            }
        }
    }

    if(initialAmount == 0)
    {
        cout << "\nIt seems like you have not chosen a single XTREME Game" << endl;
        cout << "Please enter your preferred date again\n" << endl;
        DateSelection();
    }else
    {
        cout << "\nPROCESSING....\n" << endl;
        cout <<"Due Amount: " << fixed << setprecision(2) << initialAmount << endl;
        initialAmountF = initialAmount;
        if(day == 21)
        {
            for(int i = 0; i < 9; i++)
            {
                d21[i] = internalMod[i];
            }
        }else if(day == 22)
        {
            for(int i = 0; i < 9; i++)
            {
                d22[i] = internalMod[i];
            }
        }else if(day == 23)
        {
            for(int i = 0; i < 9; i++)
            {
                d23[i] = internalMod[i];
            }
        }else if(day == 24)
        {
            for(int i = 0; i < 9; i++)
            {
                d24[i] = internalMod[i];
            }
        }else if(day == 25)
        {
            for(int i = 0; i < 9; i++)
            {
                d25[i] = internalMod[i];
            }
        }else if(day == 26)
        {
            for(int i = 0; i < 9; i++)
            {
                d26[i] = internalMod[i];
            }
        }else if(day == 27)
        {
            for(int i = 0; i < 9; i++)
            {
                d27[i] = internalMod[i];
            }
        }
        //After Updating the Available games, we move to PromoCode Function
        PromoCode();
    }
}

void DateConfirmationJanuary(int day_,int e0,int e1,int e2,int e3,int e4,int e5,int e6,int e7,int e8)
{
    int elements[9];
    int eSize = sizeof(elements)/sizeof(elements[0]);
    elements[0] = e0;
    elements[1] = e1;
    elements[2] = e2;
    elements[3] = e3;
    elements[4] = e4;
    elements[5] = e5;
    elements[6] = e6;
    elements[7] = e7;
    elements[8] = e8;

    int day = day_;

    int internalMod[eSize] = {-1,-1,-1,-1,-1,-1,-1,-1,-1};

    cout << "-----------------------------" << endl;
    for(int i = 0; i < eSize;i++)
    {
        if(elements[i] != -1)
        {
            cout << extremeGames[elements[i]] << endl;
        }
    }
    cout << "-----------------------------\n" << endl;

    //Transaction
    float initialAmount = 0;
    for(int i = 0; i < eSize; i++)
    {
        int r = -1;
        if(elements[i] != -1)
        {
            while(!(r == 0 || r == 1))
            {
                cout << "1 if YES; 0 if NO" << endl;
                cout << "Cost for this XTREME Game: " << fees[elements[i]] << endl;
                cout << "Do you want to try " << extremeGames[elements[i]] << "? ";
                cin >> r;
                if(r == 1)
                {
                    initialAmount += fees[elements[i]];
                    internalMod[elements[i]] = -1;
                    //The program will keep track the transaction that will display in the reporting(Menu 4)
                    selectedGames[elements[i]] = elements[i];
                }else if(r == 0){
                    internalMod[elements[i]] = elements[i];
                    //The program will keep track the transaction that will display in the reporting(Menu 4)
                    selectedGames[elements[i]] = -1;
                }else
                {
                    cout << "Please enter 0 or 1 only" << endl;
                }
            }
        }
    }

    if(initialAmount == 0)
    {
        cout << "\nIt seems like you have not chosen a single XTREME Game" << endl;
        cout << "Please enter your preferred date again\n" << endl;
        DateSelection();
    }else
    {
        cout << "\nPROCESSING....\n" << endl;
        cout <<"Due Amount: " << fixed << setprecision(2) << initialAmount << endl;
        initialAmountF = initialAmount;
        if(day == 1)
        {
            for(int i = 0; i < 9; i++)
            {
                j01[i] = internalMod[i];
            }
        }else if(day == 2)
        {
            for(int i = 0; i < 9; i++)
            {
                j02[i] = internalMod[i];
            }
        }else if(day == 3)
        {
            for(int i = 0; i < 9; i++)
            {
                j03[i] = internalMod[i];
            }
        }else if(day == 4)
        {
            for(int i = 0; i < 9; i++)
            {
                j04[i] = internalMod[i];
            }
        }else if(day == 5)
        {
            for(int i = 0; i < 9; i++)
            {
                j05[i] = internalMod[i];
            }
        }
        //After Updating the Available games, we move to PromoCode Function
        PromoCode();
    }
}
//#endregion

//#region Menu 3
/* Summary
   PromoCode Function will process the deducted amount depending on the discount choosen by the user through code input
   If the code is valid then we will passed the discounted amount that will be paid, if the user skip or dont have the code
   The original amount will be passed meaning the user dont have discount. The Transaction Function will take an integer as
   an argument. This integer is the value of the passed amount in the PromoCode Function.
*/
void PromoCode()
{
    int r = -1;
    bool codeRedeemed = false;
    bool skipped = false;
    float discount = 0;
    string code;

    while(!(r == 1 || r == 0))
    {
        cout << "Enter 1 if YES; 0 if NO" << endl;
        cout << "Do you have a Promo Code? "; cin >> r;

        if(r == 1)
        {
            while(!codeRedeemed)
            {
                cout << "(Enter 'SKIP' to Cancel)Please Enter A Valid Code: "; cin >> code;
                if(code != "INVALID")
                {
                    for(int i = 0; i < codeSize; i++)
                    {
                        if(promoCodes[i] == code)
                        {
                            promoCodes[i] = "INVALID";
                            codeRedeemed = true;
                            discount = codeDeduction[i];
                            break;
                        }else if(code == "SKIP")
                        {
                            codeRedeemed = true;
                            skipped = true;
                            discount = 0.0;
                            break;
                        }
                        else
                        {
                            cout << "......" << endl;
                        }
                    }
                }else
                {
                    cout << "\nPlease Enter a Valid Code" << endl;
                }
            }
        }else if(r == 0)
        {
            cout <<  "You have 0% Discount.\n" << endl;
            Transaction(initialAmountF,discount);
        }else
        {
            cout << "\nSorry you can only enter 0 or 1" << endl;
        }
    }


    if(codeRedeemed)
    {
        if(skipped)
        {
            cout << "\nCode Redemption CANCELED" << endl;
        }else
        {
            cout << "\nSuccessfully Redeemed" << endl;
        }

        /* Remove comment to see the promo codes array///
        for(string x : promoCodes)
        {
            cout << x << endl;
        }
        //*/

        cout << "You have " << fixed << setprecision(0) << discount << "% Discount.\n" << endl;
        float deduct = discount/100;
        float pay = initialAmountF - (initialAmountF * deduct);
        Transaction(pay,discount);
    }
}

/*  Summary
    The user has the freedom to pick what transaction method available for this program.
    This program don't have the value of the personal bank account of the user. Just like
    in real life application, it is handled by third party application such as GCash or PayPal.
    But this program still know if the user enter the right amount to be paid. In this case, the program
    uses a universal wallet for the user. In that way we will only know their balance which is important
    because the program will deduct their balance by the due amount. The program will have a hold of this
    value meaning the next time we transac using the same account, it will never have the same balance as long
    as we are still running the program. After the completing the transaction, we will run the Report Function
*/
void Transaction(float pay_, float discount_)
{
    float amountDue = pay_;
    float amountpay;
    float discount = discount_;
    cout << "Due Amount: " << fixed << setprecision(2) << amountDue << endl;

    int paymentMode = -1;

    while(!(paymentMode > -1 && paymentMode < 4))
    {
        cout << "Payment Method" << endl;
        cout << "0 - GCash\n1 - PayMaya\n2 - Card\n3 - PayPal" << endl;
        cout << "Selected Payment Method: "; cin >> paymentMode; cout << "\n" << endl;
        if(paymentMode == 0) //GCash
        {
            cout << paymentMethod[paymentMode] << " has been selected" << endl;
            string mobile,pin;

            cout << "Enter Mobile Number: "; cin >> mobile;
            cout << "Enter PIN: "; cin >> pin;

            cout << "\nAccount Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;

            while(amountpay != amountDue)
            {
                cout << "Please Pay the exact amount: "; cin >> amountpay;
                if(amountpay == amountDue)
                {
                    accBalance[ID] -= amountDue;
                    cout << "\nYour New Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;
                    cout << "Transaction Complete. Thank You " << registeredFNames[ID] << " " << registeredLNames[ID] << endl;
                    //After the completing the transaction, the program will run the Report Function
                    Report(amountpay,paymentMode,discount);
                }else
                {
                    cout << "\nTo complete this transaction, pay the exact amount.\n" << endl;
                }
            }

        }else if(paymentMode == 1) //PayMaya
        {
            cout << paymentMethod[paymentMode] << " has been selected" << endl;
            string email,password,otp;

            cout << "Enter Email or Mobile no. :"; cin >> email;
            cout << "Enter Password: " ; cin >> password;
            cout << "Enter OTP: " ; cin >> otp;

           cout << "\nAccount Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;

            while(amountpay != amountDue)
            {
                cout << "Please Pay the exact amount: "; cin >> amountpay;
                if(amountpay == amountDue)
                {
                    accBalance[ID] -= amountDue;
                    cout << "\nYour New Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;
                    cout << "Transaction Complete. Thank You " << registeredFNames[ID] << " " << registeredLNames[ID] << endl;
                    //After the completing the transaction, the program will run the Report Function
                    Report(amountpay,paymentMode,discount);
                }else
                {
                    cout << "\nTo complete this transaction, pay the exact amount.\n" << endl;
                }
            }

        }else if(paymentMode == 2) //Card
        {
            cout << paymentMethod[paymentMode] << " has been selected" << endl;
            string nameOnCard,cardNumber,exp,cvv,postalCode;

            cout << "Name on card: "; cin >> nameOnCard;
            cout << "Credit Card Number: "; cin >> cardNumber;
            cout << "Expiration: "; cin >> exp;
            cout << "CVV: "; cin >> cvv;
            cout << "Postal Code: "; cin >> postalCode;

            cout << "\nAccount Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;

            while(amountpay != amountDue)
            {
                cout << "Please Pay the exact amount: "; cin >> amountpay;
                if(amountpay == amountDue)
                {
                    accBalance[ID] -= amountDue;
                    cout << "\nYour New Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;
                    cout << "Transaction Complete. Thank You " << registeredFNames[ID] << " " << registeredLNames[ID] << endl;
                    //After the completing the transaction, the program will run the Report Function
                    Report(amountpay,paymentMode,discount);
                }else
                {
                    cout << "\nTo complete this transaction, pay the exact amount.\n" << endl;
                }
            }

        }else if(paymentMode == 3) //PayPal
        {
            cout << paymentMethod[paymentMode] << " has been selected" << endl;
            string email,password;

            cout << "Enter Email or Mobile number: "; cin >> email;
            cout << "Password or One-time Code: "; cin >> password;

            cout << "\nAccount Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;

            while(amountpay != amountDue)
            {
                cout << "Please Pay the exact amount: "; cin >> amountpay;
                if(amountpay == amountDue)
                {
                    accBalance[ID] -= amountDue;
                    cout << "\nYour New Balance: " << fixed << setprecision(2) << accBalance[ID] << endl;
                    cout << "Transaction Complete. Thank You " << registeredFNames[ID] << " " << registeredLNames[ID] << endl;
                    //After the completing the transaction, the program will run the Report Function
                    Report(amountpay,paymentMode,discount);
                }else
                {
                    cout << "\nTo complete this transaction, pay the exact amount.\n" << endl;
                }
            }
        }else
        {
            cout << "Sorry you can only choose 0 to 3 for Payment Method" << endl;
        }
    }
}
//#endregion

//#region Menu 4
/* Summary
    Report Function will simply print or display the transaction made the history. It will show who made the transaction,
    what day did he/she scheduled, what kind of sports/games the customer picked in their chosen date. It also include the subtotal
    deduction and discount, total amount and amount paid. After the Report Function, the customer can choose to exit the program or go
    back to menu where the customer can login or register again.
*/
void Report(float amountPaid, int payMode, float discount)
{
   // for(int x: selectedGames)
    //    cout << x << endl;

    string month;
    string year;
    string gender;

    //Determine Gender
    if(correspondingGender[ID] == 'M' || correspondingGender[ID] == 'm')
    {
        gender = "GENDER: MALE";
    }else
    {
        gender = "GENDER: FEMALE";
    }


    //Determine the Selected Date
    if(selectedM == 0)
    {
        month = "DECEMBER";
        year = ", 2021";
    }else
    {
        month = "JANUARY";
        year = ", 2022";
    }

    float totalInAmount;
    cout << "\n-----------------------------" << endl;
    cout << "XTREME WORLD \t\tREPORT\n" << endl;
    cout << "BILL TO: " << registeredFNames[ID] << " " << registeredLNames[ID] << endl;
    cout << "--------USER DETAILS---------" << endl;
    cout << "BIRTH DATE: " << correspondingMM[ID] << "/" << correspondingDD[ID] << "/" << correspondingYY[ID] << endl;
    cout << gender << endl;
    cout << "-----------------------------" << endl;
    cout << "TRANSACTION DETAILS:" << endl;
    cout << "SCHEDULED FOR " << month << " " << selectedD << year << endl;
    cout << "PAYMENT METHOD: " << paymentMethod[payMode] << endl;
    cout << "\n-----------------------------" << endl;
    cout << "XTREME GAMES\t| " << "FEE" << endl;
    cout << "----------------|------------" << endl;
    for(int i = 0; i < gameSize;i++)
    {
        if(selectedGames[i] != -1)
        {
            cout << extremeGames[selectedGames[i]] << "\t| " << fees[selectedGames[i]]<<endl;
            totalInAmount += fees[selectedGames[i]];
        }
    }

    //Calculate the total amount after the discount
    float discountedDeduction = totalInAmount * (discount/100);
    float totalAm = totalInAmount - discountedDeduction;
    cout << "----------------|------------" << endl;
    cout << "SUBTOTAL AMOUNT:| " <<  fixed << setprecision(2) << totalInAmount << endl;
    cout << "DISCOUNT:\t| " << fixed << setprecision(0) << discount << "%" << endl;
    cout << "DEDUCTION:\t| " << fixed << setprecision(2) << discountedDeduction * -1 << endl;
    cout << "TOTAL AMOUNT:\t| " << fixed << setprecision(2) << totalAm << endl;
    cout << "AMOUNT PAID:\t| " <<  fixed << setprecision(2) << amountPaid << endl;
    cout << "-----------------------------\n" << endl;

    //Reset Selected Games and Selected  Date After the Report
    for(int i = 0;i < gameSize; i++)
    {
        selectedGames[i] = -1;
    }
    selectedD = -1;
    selectedM = -1;

    //After the Report, the user has to choose to go back to menu or exit
    int respond = -1;
    while (!(respond == 1 || respond == 0))
    {
        cout << "\nEnter 1 to go back in Main Menu\nEnter 0 to Exit\n"; cin >> respond;
        if(respond == 1) //Main Menu
        {
            main();
        }else if(respond == 0) //Exit
        {
            Exit();
        }else
        {
            cout << "\nYou can Enter 1 or 0 only." << endl;
        }
    }
}

//Function to terminate the program
void Exit()
{
    cout << "\nPlease Visit XTREME WORLD Again. Thank You!" << endl;
    exit(1);

}

//#endregion
