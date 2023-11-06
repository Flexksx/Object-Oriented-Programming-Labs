public class BankApplicationMain {
    public static void main(String[] args) {
        BankAccount ba1 = new BankAccount("Vaniusha", 10, "694201337");
        BankAccount ba2 = new BankAccount("Jora", 20, "42992323");
        //Since I did not put them in any data structure, i just passed the transaction method an object.
        ba1.deposit(100);
        ba1.showBalance();
        ba2.deposit(50);
        ba1.transferFunds(ba2, 1000);
        ba2.blockAccount();
        ba1.transferFunds(ba2, 20);
    }
}

