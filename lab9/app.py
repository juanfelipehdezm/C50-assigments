import sqlite3
from flask import Flask, redirect, render_template, request

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# ConfigureLibrary to use SQLite database
conn = sqlite3.connect("birthdays.db", check_same_thread=False)
db = conn.cursor()


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        """Add the user's entry into the database"""
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")
        db.execute(
            "INSERT INTO birthdays (name, month, day) VALUES(?, ?, ?)", (name, month, day))
        return redirect("/")

    else:
        """Display the entries in the database on index.html"""
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)
