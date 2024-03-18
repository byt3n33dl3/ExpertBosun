from cryptography.fernet import Fernet
from time import sleep
from os import system
from colorama import Fore, Style

system("pip install -r requirements.txt")
system("cls || clear")
while True:
    print(Fore.LIGHTGREEN_EX + "\tWELCOME TO THE ENCRYPTER" + Style.RESET_ALL +
          Fore.LIGHTRED_EX + "\n    Choose Your File And Encrypt It\n\t    Or Decrypt It")
    sleep(1)
    print("""{}
    \t0giv Encrypter                                  
    """.format(Fore.RED, Style.RESET_ALL))
    sleep(1)
    print(Fore.LIGHTGREEN_EX + "{/} " + Style.RESET_ALL + "By " +
          Fore.RED + Style.BRIGHT + "0giv\n" + Style.RESET_ALL)
    sleep(1)

    key = Fernet.generate_key()

    menu = int(input(Fore.LIGHTMAGENTA_EX +
               " \t1- Encrypt It\n \t2- Decrypt It\n\t3- Exit\n" + Fore.LIGHTYELLOW_EX + "\n  Entry: "))

    if menu == 1:
        savekey = input(
            str("Where Would Like To Save Key File?(Use '//'): " + Style.RESET_ALL))
        choosenfile = input(
            str("Enter The File Path With File Extension(Use '//'): " + Style.RESET_ALL))

        encryptedfilepath = input(
            str(Fore.LIGHTWHITE_EX + "Where Would Like To Save Encrypted File(With Extention)?(Use '//'): " + Style.RESET_ALL))
        
        system("cls||clear")
        
        with open(f"{savekey}", "wb") as keyfile:
            keyfile.write(key)
            sleep(1)
            print(Fore.RED + "\n\tKey File Created" + Style.RESET_ALL)

        with open(f"{savekey}", "rb") as key_file:
            key = key_file.read()
        sleep(1)
        f = Fernet(key)

        with open(f"{choosenfile}", "rb") as orginal_file:
            orginal = orginal_file.read()

        encrypt = f.encrypt(orginal)

        with open(f"{encryptedfilepath}", "wb") as encfile:
            encfile.write(encrypt)
            sleep(1)
            print(Fore.LIGHTBLACK_EX + "\n\tEnc File Created" + Style.RESET_ALL)
            sleep(2)
            system("cls || clear")
    elif menu == 2:
        savekey = input(
            str("Where Is The Key File?(Use '//'): " + Style.RESET_ALL))
        enc_file = input(
            str(Fore.LIGHTGREEN_EX + "Enter The Encrypted File(Use '//'): "))
        decryptfile = input(
            str("Where Would Like To Save The Decrypted File(Use '//'): " + Style.RESET_ALL))

        with open(f"{savekey}", "rb") as key_file:
            key = key_file.read()
        sleep(1)
        token = Fernet(key)

        with open(f"{enc_file}", "rb") as encrypted_file:
            encrypted = encrypted_file.read()

        decrypt = token.decrypt(encrypted)

        with open(f"{decryptfile}", "wb") as decryptedfile:
            decryptedfile.write(decrypt)
    elif menu == 3:
        sleep(1)
        print(Fore.RED + "Exiting..." + Style.RESET_ALL)
        sleep(2)
        system("cls || clear")
        break
    else:
        sleep(1)
        print(Fore.RED + "WRONG ENTRY BUDDY!" + Style.RESET_ALL)
        sleep(2)
        system("cls || clear")
        continue
