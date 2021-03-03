function [tau_ff,qm_ref,qm_d_ref] = FFSingleAxis(J,Mii,c,f_a,f_b,f_asym,f_coul,f_vis,q0,q1,q2,q3,q4,q_back,sE,sF,tau_a,tau_c,tau_g,u)
%#codegen

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    16-Oct-2020 17:19:28

t2 = Mii.*q2;
t3 = Mii.*q3;
t4 = Mii.*q4;
t5 = f_b.*q1;
t6 = f_vis.*q1;
t7 = f_vis.*q2;
t8 = f_vis.*q3;
t9 = q1.*sF;
t10 = f_b.^2;
t11 = q2.^2;
t12 = sF.^2;
t15 = 1.0./c;
t13 = tanh(t5);
t14 = tanh(t9);
t16 = t13.^2;
t17 = t14.^2;
t18 = f_a.*t13;
t19 = f_coul.*t14;
t20 = t16-1.0;
t21 = t17-1.0;
t32 = f_asym+t2+t6+t18+t19+tau_a+tau_c+tau_g;
t22 = f_a.*f_b.*q2.*t20;
t23 = f_a.*f_b.*q3.*t20;
t24 = f_coul.*q2.*sF.*t21;
t25 = f_coul.*q3.*sF.*t21;
t30 = t10.*t11.*t18.*t20.*2.0;
t31 = t11.*t12.*t19.*t21.*2.0;
t33 = sE.*t32;
t26 = -t22;
t27 = -t23;
t28 = -t24;
t29 = -t25;
t34 = tanh(t33);
t35 = t34.^2;
t37 = t3+t7+t26+t28;
t38 = t4+t8+t27+t29+t30+t31;
t36 = t35-1.0;
tau_ff = t32./u+J.*u.*(q2+t15.*t38-q_back.*sE.*t36.*t38+q_back.*sE.^2.*t34.*t36.*t37.^2.*2.0);
if nargout > 1
    qm_ref = u.*(q0+q_back.*t34+t15.*t32);
end
if nargout > 2
    qm_d_ref = u.*(q1+t15.*t37-q_back.*sE.*t36.*t37);
end
