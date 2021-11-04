SELECT
    title
FROM
    movies
JOIN
    stars
ON
    movies.id = stars.movie_id
JOIN 
    people 
ON
    people.id = stars.person_id
WHERE
    people.name 
IN ('Johnny Depp', 'Helena Bonham Carter')
GROUP BY movies.title
HAVING COUNT(movies.title) = 2;