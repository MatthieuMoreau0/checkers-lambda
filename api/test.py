import subprocess

if __name__ == "__main__":
  with open('test.json', 'r') as f:
    process = subprocess.run(["../build/Debug/checkers-lambda.exe", f.read()], capture_output=True, text=True)

    print(process.stdout)
