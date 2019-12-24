import random


def guess():
    print('Guess the number, 1 to 100')
    print('I\'ll also be guessing! Try to beat me!')

def game():
    loop = True
    guess_count = 0
    number = random.randint(1,100)
    compNum = random.randint(1, 100)
    max_guess = 100
    min_guess = 1
    while True:
        
        
        userInput = int(input())

        if number > userInput:
            print('Too small')
            if number > compNum:
                min_guess = compNum + 1
                print('My guess is ' + (str(compNum)) + ', it\'s too small!')
                compNum = random.randint(min_guess, max_guess)
                
            elif number < compNum:
                max_guess = compNum - 1
                print('My guess is ' + (str(compNum)) + ', it\'s too big!')
                compNum = random.randint(min_guess, max_guess)
                
            elif number == compNum:
                print('My guess is ' + (str(compNum)) + ', it\'s correct!')
                
                print('I\'ve beaten you!')
                guess_count = guess_count + 1
                print('It took me ' + (str(guess_count)) + ' guess(es).')
                print('Would you like to play again?')
                cont = input()
                if cont == 'yes':
                    guess()
                    game()
                else:
                    print('We won\'t play again then')
                loop = False
                
            guess_count = guess_count + 1
        elif number < userInput:
            print('Too big')
            if number > compNum:
                min_guess = compNum + 1
                print('My guess is ' + (str(compNum)) + ', it\'s too small!')
                compNum = random.randint(min_guess, max_guess)
                
            elif number < compNum:
                max_guess = compNum - 1
                print('My guess is ' + (str(compNum)) + ', it\'s too big!')
                compNum = random.randint(min_guess, max_guess)
                
            elif number == compNum:
                print('My guess is ' + (str(compNum)) + ', it\'s correct!')
        
                print('I\'ve beaten you!')
                guess_count = guess_count + 1
                print('It took me ' + (str(guess_count)) + ' guess(es).')
                print('Would you like to play again?')
                cont = input()
                if cont == 'yes':
                    guess()
                    game()
                else:
                    print('We won\'t play again then')
                loop = False
            guess_count = guess_count + 1
        elif number == userInput:
            print('Correct')
            print('Ah damn, you beat me!')
            guess_count = guess_count + 1
            print('It took you ' + (str(guess_count)) + ' guess(es).')
            loop = False
            print('Would you like to play again?')
            cont = input()
            if cont == 'yes':
                guess()
                game()
            else:
                print('We won\'t play again then')

guess()
game()
