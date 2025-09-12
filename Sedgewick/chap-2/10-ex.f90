program pgcd
 implicit none
 
 integer :: u
 integer :: v
 integer :: t

  v = 23
  
  u = 12

  if (u<v) then
      t=u
      u=v
      v=t
  end if
 
  do while (v>0)
    
    u = u -v
  end do

  print *, u

end program pgcd
