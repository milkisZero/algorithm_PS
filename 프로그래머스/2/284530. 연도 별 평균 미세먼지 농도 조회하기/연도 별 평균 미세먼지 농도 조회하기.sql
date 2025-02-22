select year(YM) as YEAR, round(avg(PM_VAL1), 2) as PM10, round(avg(PM_VAL2), 2) as 'PM2.5'
from AIR_POLLUTION 
group by YEAR,LOCATION2
having LOCATION2 = '수원'
order by YEAR asc
