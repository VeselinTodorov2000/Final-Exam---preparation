SELECT m.NAME, m.BIRTHDATE
FROM MOVIESTAR m
WHERE m.NAME NOT LIKE '%Jr.%' AND m.NAME NOT IN (SELECT NAME
                                                 FROM MOVIESTAR
                                                     JOIN STARSIN S
                                                     ON MOVIESTAR.NAME = S.STARNAME
                                                     JOIN MOVIE
                                                     ON S.MOVIETITLE=MOVIE.TITLE
                                                     WHERE INCOLOR = 'Y');

                                                     SELECT NAME, YEAR(BIRTHDATE) AS BIRTHYEAR, COUNT(STUDIONAME) AS STUDIOS
FROM MOVIESTAR
JOIN STARSIN on MOVIESTAR.NAME = STARSIN.STARNAME
JOIN MOVIE on STARSIN.MOVIETITLE = MOVIE.TITLE
WHERE GENDER = 'F'
  AND NAME IN (SELECT ms.NAME
               FROM MOVIESTAR ms
                        JOIN STARSIN S on ms.NAME = S.STARNAME
               GROUP BY ms.NAME
               HAVING COUNT(MOVIETITLE) <= 6)
GROUP BY NAME, BIRTHDATE;
