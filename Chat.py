
import  nltk
from nltk.chat.util import Chat, reflections

pairs=[
    [r"hi|hey|hello",
    ["hello,How can I help you?"]],
    
    [
        r"what is your name ?",
        ["hii , I am a Quick Bot!"]
    ],
    [
        r"how are you?",
        ["i am good"]
    ],
    [
        r"i am also good",
        ["nice to hear that , how can i help you"]


    ],
    [
        r"(.*) available rooms| (.*) rooms available",
        ["We offer a double room and a single room. Which one would you like to know more about?"]
    ],
    [
        r"double room",
        ["It has a 2 rooms, can accomodate maximum of 4 people."]
    ],
    [
        r"single room",
        ["It has a 1 room, can accomodate maximum of 2 people."]
    ],
     [
        r"(.*) pool?",
        ["Yes", "Yes, it has a baby pool and a deep pool for adults."]
    ],
    [
        r"(.*) rates|(.*)rate",
        ["For which room would you like to know?"]
    ],
     [
        r"(.*) single room",
        ["It is Rs.2500/day"]
    ],
    [
        r"(.*) double room",
        ["It is Rs.4500/day"]
    ],
    [
        r"Is breakfast included?",
        ["Yes!", "Breakfast is complimentary"]
    ],
      [
        r"(.*) book a room?",
        ["Head over to the hotel's website or contact the reception"]
    ],
     [
        r"Thanks",
        ["BBye take care. See you soon :) ",
            "It was nice talking to you. See you soon :)"]
    ],
]

def chat():
    print(" hello , i am a hotel help desk chatbot!")
    chat=Chat(pairs,reflections)
    chat.converse()

if __name__=="__main__":
    chat()