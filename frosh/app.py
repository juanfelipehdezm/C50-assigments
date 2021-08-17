from flask import Flask, render_template, request, redirect
import sqlite3

app = Flask(__name__)

# creating the database to keep track or the registrants
conn = sqlite3.connect("registrans.db", check_same_thread=False)
db = conn.cursor()

db.executescript("""
    DROP TABLE IF EXISTS registrans;

    CREATE TABLE registrans(
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
        name TEXT NOT NULL,
        sport TEXT NOT NULL
    );
""")
print("Data base created")

# lis of the sports availables
SPORTS = ["Dodgeball", "Flag Football",
          "Soccer", "Volleyball", "Ultimate Frisbee"]


@app.route("/")
# rendering index.html to get the information from the user
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/error", methods=["POST"])
# checking if the user information is correct and if not handle it
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name:
        return render_template("error.html", message="Missing name")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Sport not available")

    db.execute("INSERT INTO registrans (name, sport) VALUES(?, ?)", (name, sport))

    return redirect("/registrans")


@app.route("/registrans")
# lets show the database in another html file
def registrants():
    registrans = db.execute("SELECT * FROM registrans")
    return render_template("registrans.html", registrans=registrans)
