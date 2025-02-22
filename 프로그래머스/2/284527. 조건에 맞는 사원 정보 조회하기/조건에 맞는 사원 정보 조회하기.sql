select sum(c.SCORE) as SCORE,	c.EMP_NO, 	b.EMP_NAME ,b.POSITION,	b.EMAIL
FROM HR_EMPLOYEES b JOIN HR_GRADE c ON b.EMP_NO = c.EMP_NO
group by c.EMP_NO, c.YEAR 
having c.YEAR = '2022'
order by  SCORE desc
limit 1