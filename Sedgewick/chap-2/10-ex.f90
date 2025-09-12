program pgcd
 implicit none
 
 integer :: u
 integer :: v
 integer :: t

  print *, 'Please enter two numbers.'
  read (5,*) u 

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
