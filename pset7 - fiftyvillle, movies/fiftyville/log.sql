-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Action: Look for crime_scene_reports at the incident date

-- Suspects for thief: Ernest, Russell, Madison

-- Suspects for location:

-- Sucspects for acomplice: (375) 555-8161

SELECT
    description
FROM
    crime_scene_reports
WHERE
    year = 2020
    AND
    month = 7
    AND
    day = 28
    AND
    street = 'Chamberlin Street';

-- Result: Theft of the CS50 duck took place at 10:15am at
-- the Chamberlin Street courthouse. Interviews were conducted
-- today with three witnesses who were present at the time — each
-- of their interview transcripts mentions the courthouse.

-- Action: Look for transript from interviews

SELECT
    name, transcript
FROM
    interviews
WHERE
    year = 2020
    AND
    month = 7
    AND
    day = 28;

-- Result - Three Relevant interviews

-- Ruth| Sometime within ten minutes of the theft, I saw the thief get into
-- a car in the courthouse parking lot and drive away. If you have
-- security footage from the courthouse parking lot, you might want to
-- look for cars that left the parking lot in that time frame.

-- Eugene| I don't know the thief's name, but it was someone I recognized.
-- Earlier this morning, before I arrived at the courthouse, I was
-- walking by the ATM on Fifer Street and saw the thief there
-- withdrawing some money.

-- Raymond | As the thief was leaving the courthouse, they called someone who
-- talked to them for less than a minute. In the call, I heard the
-- thief say that they were planning to take the earliest flight out of
-- Fiftyville tomorrow. The thief then asked the person on the other end
-- of the phone to purchase the flight ticket.

-- Action: Look for activity and license_plate from courthouse_security_logs

SELECT
    activity, hour, minute, license_plate
FROM
    courthouse_security_logs
WHERE
    year = 2020
    AND
    month = 7
    AND
    day = 28;

-- Results:
-- activity | hour | minute | license_plate
-- entrance | 8 | 2 | 1M92998
-- entrance | 8 | 2 | N507616
-- exit | 8 | 2 | 1M92998
-- exit | 8 | 2 | N507616
-- entrance | 8 | 7 | 7Z8B130
-- exit | 8 | 7 | 7Z8B130
-- entrance | 8 | 13 | 47MEFVA
-- exit | 8 | 13 | 47MEFVA
-- entrance | 8 | 15 | D965M59
-- entrance | 8 | 15 | HW0488P
-- exit | 8 | 15 | D965M59
-- exit | 8 | 15 | HW0488P
-- entrance | 8 | 18 | L93JTIZ
-- entrance | 8 | 23 | 94KL13X
-- entrance | 8 | 25 | L68E5I0
-- entrance | 8 | 25 | HOD8639
-- exit | 8 | 25 | HOD8639
-- exit | 8 | 34 | L68E5I0
-- entrance | 8 | 34 | 1106N58
-- entrance | 8 | 34 | W2CT78U
-- exit | 8 | 34 | W2CT78U
-- entrance | 8 | 36 | 322W7JE
-- entrance | 8 | 38 | 3933NUH
-- exit | 8 | 38 | 3933NUH
-- entrance | 8 | 42 | 0NTHK55
-- entrance | 8 | 44 | 1FBL6TH
-- exit | 8 | 44 | 1FBL6TH
-- entrance | 8 | 49 | P14PE2Q
-- exit | 8 | 49 | P14PE2Q
-- entrance | 8 | 50 | 4V16VO0
-- exit | 8 | 50 | 4V16VO0
-- entrance | 8 | 57 | 8LLB02B
-- exit | 8 | 57 | 8LLB02B
-- entrance | 8 | 59 | O784M2U
-- exit | 8 | 59 | O784M2U
-- entrance | 9 | 14 | 4328GD8
-- entrance | 9 | 15 | 5P2BI95
-- entrance | 9 | 20 | 6P58WS2


-- Action: Get peoples name. phone_number, and passport_number based on the license
-- plate present in the courthouse

SELECT
    name, phone_number, passport_number, license_plate
FROM
    people
WHERE
    license_plate
IN(
    SELECT
        license_plate
    FROM
        courthouse_security_logs
    WHERE
    year = 2020
    AND
    month = 7
    AND
    day = 28
);

-- Results:
-- name | phone_number | passport_number | license_plate
-- Jordan | (328) 555-9658 | 7951366683 | HW0488P
-- Patrick | (725) 555-4692 | 2963008352 | 5P2BI95
-- Amber | (301) 555-4174 | 7526138472 | 6P58WS2
-- Brandon | (771) 555-6667 | 7874488539 | R3G7486
-- Carolyn | (234) 555-1294 | 3925120216 | P14PE2Q
-- Joshua | (267) 555-2761 | 3761239013 | 1FBL6TH
-- Debra |  | 2750542732 | 47MEFVA
-- Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
-- Roger | (130) 555-0289 | 1695452385 | G412CB7
-- Madison | (286) 555-6063 | 1988161715 | 1106N58
-- Danielle | (389) 555-5198 | 8496433585 | 4328GD8
-- Wayne | (056) 555-0309 |  | D965M59
-- Russell | (770) 555-1861 | 3592750733 | 322W7JE
-- Michael | (529) 555-7276 | 6117294637 | HOD8639
-- Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
-- Vincent |  | 3011089587 | 94MV71O
-- Mary | (188) 555-4719 |  | C194752
-- Ralph | (771) 555-7880 | 6464352048 | 3933NUH
-- Peter | (751) 555-6567 | 9224308981 | N507616
-- Amanda | (821) 555-5262 | 1618186613 | RS7I6A0
-- Denise | (994) 555-3373 | 4001449165 | NRYN856
-- Thomas | (286) 555-0131 | 6034823042 | WD5M8I6
-- John | (016) 555-9166 | 8174538026 | 4468KVT
-- Ethan | (594) 555-6254 | 2996517496 | NAW9653
-- Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- Rachel | (006) 555-0505 |  | 7Z8B130
-- Donna |  |  | 8LLB02B
-- Sophia | (027) 555-1068 | 3642612721 | 13FNH73
-- Judith |  | 8284363264 | 4963D92
-- Jeremy | (194) 555-5027 | 1207566299 | V47T75I
-- Daniel | (971) 555-6468 | 7597790505 | FLFN3W0
-- George |  | 4977790793 | L68E5I0
-- Alice | (031) 555-9915 | 1679711307 | 1M92998
-- Andrew | (579) 555-5030 |  | W2CT78U
-- Berthold | (375) 555-8161 |  | 4V16VO0
-- Frank | (356) 555-6641 | 8336437534 | 207W38T


-- Action: Now look ATM transactions on Fifer Street on that day

SELECT
    people.name
FROM
    people
JOIN
    bank_accounts
ON
    people.id = bank_accounts.person_id
WHERE
    bank_accounts.account_number
IN(
    SELECT
        account_number
    FROM
        atm_transactions
    WHERE
        year = 2020
        AND
        month = 7
        AND
        day = 28
        AND
        atm_location = 'Fifer Street'
);

-- Results: Ernest, Robert, Russell, Roy, Bobby, Elizabeth, Danielle,
-- Madison, Victoria

-- Action: Look at the caller and receiver of phone call

SELECT
    caller, receiver, duration
FROM
    phone_calls
WHERE
    year = 2020
    AND
    month = 7
    AND
    day = 28
    AND
    duration <= 60;

-- Results:
-- caller         | reciever       | duration
-- (130) 555-0289 | (996) 555-8899 | 51
-- (499) 555-9472 | (892) 555-8872 | 36
-- (367) 555-5533 | (375) 555-8161 | 45
-- (609) 555-5876 | (389) 555-5198 | 60
-- (499) 555-9472 | (717) 555-1342 | 50
-- (286) 555-6063 | (676) 555-6554 | 43
-- (770) 555-1861 | (725) 555-3243 | 49
-- (031) 555-6622 | (910) 555-3251 | 38
-- (826) 555-1652 | (066) 555-9701 | 55
-- (338) 555-6650 | (704) 555-2131 | 54


-- Action: Find total airports in fiftyville

SELECT
    id, abbreviation, full_name
FROM
    airports
WHERE
    city = 'Fiftyville';

-- Results

-- id  | abbreviation | full_name
-- 8   | CSF | Fiftyville Regional Airport


-- Action: Look for the passengers pp number in flights from CSF for the next day

SELECT
    passengers.passport_number, flights.destination_airport_id
FROM
    flights
JOIN
    passengers
ON
    flights.id = passengers.flight_id
WHERE
    origin_airport_id = 8
    AND
    hour < 12;

-- Results:
-- name     | pp_number   | destination_airport_id
-- Ernest   | 5773159633  | 4
-- Russell  | 3592750733  | 5
-- Ernest left earlier than Russell the next morning

-- Action: Since Ernest is main suspect, he called (375) 555-8161, lets look at who this number belongs to

SELECT
    name, passport_number
FROM
    people
WHERE
    phone_number = "(367) 555-5533";

-- Result:
-- name | passport_number
-- Berthold |

-- Action: Find the destination city

SELECT
    city
FROM
    airports
WHERE
    id = 4;

-- Result:
-- city
-- London

