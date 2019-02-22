from sanic import Sanic
from sanic.response import json


app = Sanic()

@app.route('/')
async def home(request):
    return json({
        "message": "We're up! "
    })

if __name__ == "__main__":
    app.run(host="localhost", port=3000)