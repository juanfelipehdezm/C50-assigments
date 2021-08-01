-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street = "Chamberlin Street"
--Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse.
--Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
SELECT transcript FROM interviews
WHERE day = 28 AND month = 7 and year = 2020 and transcript LIKE "%courthouse%"
--Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away.
--If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.

--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse,
--I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.

--As the thief was leaving the courthouse, they called someone who talked to them for less than a minute.
--In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.
SELECT p.name
FROM people as p
INNER JOIN courthouse_security_logs AS csl
  ON p.license_plate = csl.license_plate
WHERE csl.year = 2020 AND csl.month = 7 AND csl.day = 28 AND csl.hour = 10 AND (csl.minute >= 3 AND csl.minute < 25) AND csl.activity = "exit"
--suspetc = Patrick, Ernest, Amber, Danielle, Roger, Elizabeth, Russell, Evelyn

SELECT DISTINCT p.name
FROM people AS p
INNER JOIN bank_accounts AS ba
  ON p.id = ba.person_id
INNER JOIN atm_transactions AS atm
  ON ba.account_number = atm.account_number
WHERE atm.year = 2020 AND atm.month = 7 AND atm.day = 28 AND atm.transaction_type = "withdraw" AND atm_location = "Fifer Street"

--suspects = Danielle, Bobby, Madison, Ernest, Roy, Elizabeth, Victoria, Russell

--appear twice = Danielle, Ernest, Elizabeth, Russell

SELECT p.name
FROM people AS p
INNER JOIN passengers AS ps
ON p.passport_number = ps.passport_number
WHERE ps.flight_id IN (
    SELECT id FROM flights
    WHERE day = 29 AND month = 7 AND year = 2020
    ORDER BY hour,minute
    LIMIT 1
)
--Doris, Roger, Ernest, Edward, Evelyn, Madison, Bobby, Danielle

-- appear again = Danielle, Ernest

SELECT DISTINCT p.name
FROM people as p
INNER JOIN phone_calls AS pc
  ON p.phone_number = pc.caller
WHERE pc.day = 28 AND pc.month = 7 AND pc.year = 2020 AND pc.duration < 60

--Roger Evelyn, Ernest, Madison, Russell, Kimberly, Bobby, Victoria

-- the thief is ERNEST

SELECT city FROM airports
WHERE id IN (
    SELECT destination_airport_id
    FROM flights
    WHERE day = 29 AND month = 7 AND year = 2020
    ORDER BY hour,minute
    LIMIT 1
)

-- wanted to scape to LONDON
SELECT DISTINCT p.name
FROM people as p
INNER JOIN phone_calls AS pc
  ON p.phone_number = pc.receiver
WHERE pc.day = 28 AND pc.month = 7 AND pc.year = 2020 AND pc.duration < 60 AND pc.caller IN (
    SELECT phone_number FROM people WHERE name = "Ernest"
);
-- the complice BERTHOLD
