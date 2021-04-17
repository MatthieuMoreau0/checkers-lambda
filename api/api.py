from flask import Flask, request
from flask_cors import CORS
import subprocess

#TODO: type hinting
#TODO: setup linter and formatter
app = Flask(__name__)
CORS(app, origins="http://localhost:3000", methods="POST")

@app.route('/', methods=['POST'])
def get_playable_moves():
    data = request.get_data(as_text= True)
    process = subprocess.run(["../build/Debug/checkers-lambda.exe", data], capture_output=True, text=True)
    print(process.stderr)
    return process.stdout
