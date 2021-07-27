import sqlite3
import csv

# first we create the conection to the databse
conn = sqlite3.connect("favorites.db")
# we assigned a cursor to execute the queries
db = conn.cursor()
# excecuting an script of the SQL code
db.executescript("""
    DROP TABLE IF EXISTS Shows;
    DROP TABLE IF EXISTS Genre;

    CREATE TABLE Shows (
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
        title TEXT
    );

    CREATE TABLE Genre (
        show_id INTEGER,
        genre TEXT,
        FOREIGN KEY(show_id) REFERENCES Shows(id)
    ); 
""")
# openning the csv file
with open("Favorite TV Shows - Form Responses 1.csv", "r") as file:
    dict_reader = csv.DictReader(file)

    for row in dict_reader:
        # cleanning a little the tittle columun
        title = row["title"].strip().upper()
        # inserting title into the column Title from the Shows table
        db.execute(
            "INSERT INTO Shows (title) VALUES(?)", (title,))
        db.execute("SELECT id FROM Shows WHERE title = ?", (title,))
        # extracting the ID of every title to use it in the GENRE table
        show_id = db.fetchone()[0]
        # inserting genre into the column Genre from the Genre table
        for genre in row["genres"].split(", "):
            db.execute(
                "INSERT INTO Genre (show_id, genre) VALUES(?, ?)", (show_id, genre))
    # After successfully executing an insert operation, make changes persistent into a database using the commit() of a
    # connection class.
    conn.commit()
conn.close()
print("Database created and closed")
