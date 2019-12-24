#hangman2
import random

words = ['Superman', 'Spiderman', 'God', 'Michaelangelo', 'Tupac']

#get the word chosen, display amount of dashes for word length
secret_word = random.choice(words)




#player guesses letter
def guess_turn():
    

    dashes = '-' * len(secret_word)
    print('Welcome to hangman! You know the rules, you get 5 guesses!')
    guesses_left = 5
    correct = 0
    
    while guesses_left > 0 and '-' in dashes:
        print('Guess a letter')
        print(dashes)

        user_guess = input()

        if user_guess == ' ':
            print('Please enter a single character, not a blank space!')

        elif len(user_guess) > 1:
            print('Please enter one character at a time!')
        

        elif user_guess in dashes:
            print('You\'ve guessed that letter already! Try guess another one!')
            print('You\'ve got ' + str(guesses_left) + ' guesses left!')
            

        elif user_guess in secret_word.lower():
            print('Correct!')
            dashes = update_dashes(dashes, user_guess, secret_word)
            correct += 1

        elif user_guess in secret_word.upper():
            print('Correct!')
            dashes = update_dashes(dashes, user_guess, secret_word)
            correct += 1

        elif user_guess not in secret_word:
            print('That letter is not in the secret word! Try again!')
            guesses_left -= 1
            print('You\'ve got ' + str(guesses_left) + ' guesses left!')

    if guesses_left < 1:
        print('You lose')

    elif '-' not in dashes:
        print(dashes)
        print('You win, the secret word was ' + str(secret_word))
        





def update_dashes(current_dashes, current_guess, secret):
    result = ''
    for i in range(len(secret)):
            
            if current_guess == secret[i].lower():
                result = result + current_guess

            elif current_guess == secret[i].upper():
                result = result + current_guess

            elif current_guess != secret[i]:
                result = result + current_dashes[i]

    return result

guess_turn()
    
    


