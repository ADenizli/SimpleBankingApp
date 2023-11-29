#include <iostream>

enum ActionType {
    INBOUND, OUTBOUND
};

struct User {
   int UserID;
    int UserPassword;
};

class Bank {
    private:
     std::string UserID = "12344321";
     std::string UserPassword = "1234";
     bool isLoggedIn = false;

    public:
    double totalMoney;
    bool transfer(double moneyAmount, ActionType actionType){
        switch (actionType)
        {
        case OUTBOUND:
            if (this->totalMoney >= moneyAmount){
                this->totalMoney = this->totalMoney - moneyAmount;
                return true;
            } else {
                return false;   
            }
        
        case INBOUND:
            this->totalMoney = this->totalMoney + moneyAmount;
            return true;
        default:
            return false;
            break;
        }
    }

    double getTotalMoneyInformation() {
        return this->totalMoney;
    }
    
    bool authorization(User user) {
        if (UserID == user.UserID && UserPassword == user.UserPassword)
        {
            this->isLoggedIn = true;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool logout() {
        this->isLoggedIn = false;
        return true;
    }

    void landing() {
        std::cout << "Welcome to banking system!" << std::endl;
        std::cout << "1 - Login" << std::endl;
        std::cout << "2 - Close The Application" << std::endl;
    }

    void loginCLI() {
        int enteredID;
        int enteredPassword;
        bool checkLogin;
        std::cout << "To login please enter your id number!" << std::endl;
        std::cin >> enteredID;
        std::cout << "To login, please enter your password" << std::endl;
        std::cin >> enteredPassword;
        this->authorization({UserID: enteredID, UserPassword: enteredPassword});
        checkLogin = this->isLoggedIn();

        if (checkLogin)
        {
            this->actionsCLI();
        } else {
            std::cout << 'Data which you entered is not matching' << std::endl;
        }
    }

    void actionsCLI() {
        int selectedAction;
        std::cout << "You are logged in! You can choose your action below." << std::endl;
        std::cout << "1 - Deposit Money" << std::endl;
        std::cout << "2 - Withdraw Money" << std::endl;
        std::cout << "3 - See your status" << std::endl;
        std::cin >> selectedAction;

        // CONTINUE 

        switch (selectedAction)
        {
        case 1:
            this->depositMoneyCLI();
            break;
        case 2:
            this->withdrawMoneyCLI();
            break;
        case 3:
            this->checkStatusCLI();
            break;
        
        default:
            std::cout << "Entered unvalid action please enter valid one!" << std::endl;
            this->actionsCLI();
            break;
        }

    }




};


int main() {
    return 0;
}