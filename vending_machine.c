#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ATTEMPTS     3
// create a structure of item
struct item
{
    int id;
    char name[100];
    float price;
};
// clear buffer to prevent infinite loop
void clear_input_buffer()
{
    while (getchar() != '\n')
        ;
}
// to display list of item
void display_list(struct item items[], int n)
{
    printf("Displaying the updated list of item.....\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s:$%.2lf\n", items[i].name, items[i].price);
    }
}
// to animate
void animate_dots(const char *message, int duration)
{
    printf("%s", message);
    fflush(stdout);
    for (int i = 0; i < duration; i++)
    {
        printf(".");
        fflush(stdout);
        Sleep(500); // Pause for 0.5 seconds
    }
    printf("\n");
}
// To display loyalty program
void loyalty_program()
{
    printf("Avaliable vocher \n");
    const char *voucher[] = {"RX885k", "JQ6973", "MX5533"};
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", voucher[i]);
    }
}
// check if the voucher is valid
int is_valid_Vocher(const char *voucher)
{
    const char *valid_vocher[] = {"RX885k", "JQ6973", "MX5555"};
    int count = sizeof(valid_vocher) / sizeof(valid_vocher[0]);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(voucher, valid_vocher[i]) == 0)
        {
            return 1;
        }
    }
    return 0; // Invalid voucher
}
// To handle voucher
int handle_vocher()
{

    char voucher[100];
    int attempt = MAX_ATTEMPTS;

    while (attempt > 0)
    {
        printf("Enter your voucher ,attempt left %d:", MAX_ATTEMPTS);
        scanf("%99s", voucher);
        if (is_valid_Vocher(voucher))
        {
            printf("reddemed sucessful \n");
            return 1;
        }
        else
        {
            printf("Could'nt reddem pls try again\n");
        }
        attempt--;
    }
    return 0; // voucher redemption failed
}
int handle_cash(float price)
{
    float money = 0;
    int attempt = MAX_ATTEMPTS;
    int attempt1 = MAX_ATTEMPTS;
    while (attempt > 0)
    {
        printf("Insert money (price $%.2lf):", price);
        if (scanf("%f", &money) != 1)
        {
            printf("Invalid money input!! make sure to insert money..\n");
            clear_input_buffer();

            attempt1--;
            if (attempt == 0)
            {
                printf("Too many invalid attempts! Transcation cancelled\n");
                return 0;
            }
            continue;
        }
        if (money >= price)
        {
            printf("Payment succesfull,changed returned:$%.2lf\n", money - price);
            return 1;
        }
        else
        {

            attempt--;
            printf("Insuffient Money !!attempt left: %d\n", attempt);
        }
        if (attempt == 0)
        {
            printf("Couldn't process your request,pls make sure you inserting sufficient amount\n");
            return 0;
        }
    }
}
int payment_options(struct item selected_item)
{

    const char *payment_option[] = {"cash ", "voucher"};
    int method_count = sizeof(payment_option) / sizeof(payment_option[0]);
    int method = 1;
    int attempt1 = MAX_ATTEMPTS;

    for (int i = 0; i < method_count; i++)
    {
        printf("Enter %d for %s\n", i + 1, payment_option[i]);
    }
    // Retry logic for payment option
    while (attempt1 > 0)
    {
        printf("\nChoose a payment method:");

        if (scanf("%d", &method) != 1)
        {
            printf("Invalid input!,enter numeric value:");
            clear_input_buffer();
            // payment_options(selected_item);
            attempt1--;

            if (attempt1 == 0)
            {
                printf("Too many invalid attempts .\n");
                animate_dots("\nReturning to menu", 2);
                return 0;
            }
            continue;
        }
    

    // int attempt = MAX_ATTEMPTS;
    if (method < 1 || method > method_count)
    {
        printf("Invalid payment option selected choose for (1-%d):", method_count);
      //  scanf("%d", &method);
        attempt1--;
        if (attempt1 == 0)
        {
            printf("You have excedded the number of attempt!!\n");
            animate_dots("\nReturning to menu", 2);
            return 0;
        }
    }
    else{
        break;// valid method selected 
    }
    }
    printf("You selected :%s\n", payment_option[method - 1]);
    if (method == 1)
    {
        // check if the payment is successful
        if (handle_cash(selected_item.price))
        {

            return 1;
        }
    }
    else if (method == 2)
    {
        if (handle_vocher())
        {

            return 1;
        }
    }

    // printf("Payment failed.pls try again\n");

    return 0; // payment unsuccesfull
}
void purchase_item(struct item items[], int n)
{
    int id = 0;
    int attempt = MAX_ATTEMPTS;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d for %s:$%.2lf\n", items[i].id, items[i].name, items[i].price);
    }
  
    printf("Enter the id  to purchase the corresponding item:");
    if (scanf("%d", &id) != 1)
    {
        printf("Invalid input!, Pls enter a number correspoding to the menu options.\n");
        clear_input_buffer();
        purchase_item(items, n);// Retry selection of item
        attempt--;

        //  animate_dots("\nReturning to menu", 2);

        return;
    }
    
    
    int found = 0; // To check if the ID is valid

    for (int i = 0; i < n; i++)
    {
        if (id == items[i].id)
        {
            animate_dots("processing your request", 4);

            if (payment_options(items[i]) == 1)
            {
                animate_dots("Dispensing your selected item", 4);
                printf("successfully Dispensed:%s \n", items[i].name);
            }
            else
            {
                printf("Payment not completed.cannot dispense item\n");
            }
            animate_dots("\nReturning to menu", 2);

            found = 1;
            break;
        }
    }
    
    if (!found)
    {
        printf("Id not found!!,Make sure to choose listed id\n");
        purchase_item(items, n); // Retry selection of item
       
    }
    
}

int main()
{
    // list the item in machine
    struct item items[6] = {
        {1, "lays", 5},
        {2, "Cookie", 10},
        {3, "Cola", 10},
        {4, "Cold Coffee", 15},
        {5, "Buttermilk", 15},
        {6, "Red Bull", 30}};

    int n = sizeof(items) / sizeof items[0]; // to store number of item
    int id = 0;                              // id correspond to specific item
    int option = 0;                          // for user input

    while (1)
    {
        const char *choice[] = {"Display item", "Purchase item", "loyalty program", "exit"};
        int select = sizeof(choice) / sizeof(choice[0]);
        for (int i = 0; i < 4; i++)
        {
            printf("Enter %d for %s \n", i + 1, choice[i]);
        }
        printf("Choose an option:");
        if (scanf("%d", &option) != 1)
        {
            printf("Invalid input!!,Enter valid numberic value\n");
            clear_input_buffer(); //  clear input burffer and prevent infinite loop
            continue;
            ;
        }

        switch (option)
        {
        case 1:
            animate_dots("pls wait while we update the list", 6);
            display_list(items, n);
            break;
        case 2:
            purchase_item(items, n);

            break;
        case 3:
            loyalty_program();
            break;
        case 4:
            printf("Thanks for using our service! Have a great day\n");
            exit(1);
            break;
        default:
            printf("\npls select between (1-%d)\n", select);
            break;
        }
    }
}