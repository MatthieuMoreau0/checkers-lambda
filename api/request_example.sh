PORT=5000

data=$(cat ./test.json)

curl -H "Content-Type: application/json" localhost:5000/ -d "$data"
