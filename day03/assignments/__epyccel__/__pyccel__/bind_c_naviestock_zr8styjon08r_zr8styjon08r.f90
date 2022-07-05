module bind_c_naviestock_zr8styjon08r_zr8styjon08r

  use naviestock_zr8styjon08r_zr8styjon08r, only: pressure_poisson_numba
  use naviestock_zr8styjon08r_zr8styjon08r, only: cavity_flow_numba
  use naviestock_zr8styjon08r_zr8styjon08r, only: build_up_b_numba

  use, intrinsic :: ISO_C_Binding, only : f64 => C_DOUBLE , i64 => &
        C_INT64_T
  implicit none

  contains

  !........................................
  subroutine bind_c_build_up_b_numba(n0_b, n1_b, b, rho, dt, n0_u, n1_u, &
        u, n0_v, n1_v, v, dx, dy) bind(c)

    implicit none

    integer(i64), value :: n0_b
    integer(i64), value :: n1_b
    real(f64), intent(inout) :: b(0:n1_b - 1_i64,0:n0_b - 1_i64)
    real(f64), value :: rho
    real(f64), value :: dt
    integer(i64), value :: n0_u
    integer(i64), value :: n1_u
    real(f64), intent(in) :: u(0:n1_u - 1_i64,0:n0_u - 1_i64)
    integer(i64), value :: n0_v
    integer(i64), value :: n1_v
    real(f64), intent(in) :: v(0:n1_v - 1_i64,0:n0_v - 1_i64)
    real(f64), value :: dx
    real(f64), value :: dy

    call build_up_b_numba(b, rho, dt, u, v, dx, dy)

  end subroutine bind_c_build_up_b_numba
  !........................................

  !........................................
  subroutine bind_c_pressure_poisson_numba(n0_p, n1_p, p, dx, dy, n0_b, &
        n1_b, b, nit, nt) bind(c)

    implicit none

    integer(i64), value :: n0_p
    integer(i64), value :: n1_p
    real(f64), intent(inout) :: p(0:n1_p - 1_i64,0:n0_p - 1_i64)
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64), value :: n0_b
    integer(i64), value :: n1_b
    real(f64), intent(in) :: b(0:n1_b - 1_i64,0:n0_b - 1_i64)
    integer(i64), value :: nit
    integer(i64), value :: nt

    call pressure_poisson_numba(p, dx, dy, b, nit, nt)

  end subroutine bind_c_pressure_poisson_numba
  !........................................

  !........................................
  subroutine bind_c_cavity_flow_numba(n0_u, n1_u, u, n0_v, n1_v, v, dt, &
        nx, ny, dx, dy, n0_p, n1_p, p, rho, nu, nit, nt) bind(c)

    implicit none

    integer(i64), value :: n0_u
    integer(i64), value :: n1_u
    real(f64), intent(inout) :: u(0:n1_u - 1_i64,0:n0_u - 1_i64)
    integer(i64), value :: n0_v
    integer(i64), value :: n1_v
    real(f64), intent(inout) :: v(0:n1_v - 1_i64,0:n0_v - 1_i64)
    real(f64), value :: dt
    integer(i64), value :: nx
    integer(i64), value :: ny
    real(f64), value :: dx
    real(f64), value :: dy
    integer(i64), value :: n0_p
    integer(i64), value :: n1_p
    real(f64), intent(inout) :: p(0:n1_p - 1_i64,0:n0_p - 1_i64)
    real(f64), value :: rho
    real(f64), value :: nu
    integer(i64), value :: nit
    integer(i64), value :: nt

    call cavity_flow_numba(u, v, dt, nx, ny, dx, dy, p, rho, nu, nit, nt &
          )

  end subroutine bind_c_cavity_flow_numba
  !........................................

end module bind_c_naviestock_zr8styjon08r_zr8styjon08r
