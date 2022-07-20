module bind_c_reduction_tab_5wvvpqcciry6_5wvvpqcciry6

  use reduction_tab_5wvvpqcciry6_5wvvpqcciry6, only: initialize_table
  use reduction_tab_5wvvpqcciry6_5wvvpqcciry6, only: reduction

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine bind_c_initialize_table(n0_tab, n1_tab, n2_tab, tab, nmolec &
        , n, nmol) bind(c)

    implicit none

    integer(i64), value :: n0_tab
    integer(i64), value :: n1_tab
    integer(i64), value :: n2_tab
    real(f64), intent(inout) :: tab(0:n2_tab - 1_i64,0:n1_tab - 1_i64,0: &
          n0_tab - 1_i64)
    integer(i64), value :: nmolec
    integer(i64), value :: n
    integer(i64), value :: nmol

    call initialize_table(tab, nmolec, n, nmol)

  end subroutine bind_c_initialize_table
  !........................................

  !........................................
  subroutine bind_c_reduction(n0_tab, n1_tab, n2_tab, tab, n0_tab1, tab1 &
        , n0_tab2, tab2, nmolec, nmol, n) bind(c)

    implicit none

    integer(i64), value :: n0_tab
    integer(i64), value :: n1_tab
    integer(i64), value :: n2_tab
    real(f64), intent(in) :: tab(0:n2_tab - 1_i64,0:n1_tab - 1_i64,0: &
          n0_tab - 1_i64)
    integer(i64), value :: n0_tab1
    real(f64), intent(inout) :: tab1(0:n0_tab1 - 1_i64)
    integer(i64), value :: n0_tab2
    real(f64), intent(inout) :: tab2(0:n0_tab2 - 1_i64)
    integer(i64), value :: nmolec
    integer(i64), value :: nmol
    integer(i64), value :: n

    call reduction(tab, tab1, tab2, nmolec, nmol, n)

  end subroutine bind_c_reduction
  !........................................

end module bind_c_reduction_tab_5wvvpqcciry6_5wvvpqcciry6
